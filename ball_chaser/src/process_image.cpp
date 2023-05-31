#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>


// Define a global client that can request services
ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lin_x, float ang_z)
{
    // TODO: Request a service and pass the velocities to it to drive the robot
    
    ROS_INFO_STREAM("Moving the robot");
    ball_chaser::DriveToTarget srv;


    srv.request.linear_x = lin_x;
    
    srv.request.angular_z = ang_z;
    
   if (client.call(srv))
    {
       ROS_INFO("Moving: liner_x = %f , angular_z = %f ", lin_x, ang_z);
     }
     else
     {
       ROS_ERROR("Failed to call service command_robot");
       
     }
    
}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{
 // TODO: Loop through each pixel in the image and check if there's a bright white one
    // Then, identify if this pixel falls in the left, mid, or right side of the image
    // Depending on the white ball position, call the drive_bot function and pass velocities to it
    // Request a stop when there's no white ball seen by the camera
    
    int white_pixel = 255;
    int left = img.step/3;
    int center = left*2;
    int right = img.step;
    bool ball_detected = false ;
    int ballposition = 0;
    
    for (int i = 0; i < img.height * img.step; i+=3) 
    {       
            if (img.data[i]== img.data[i+1] && img.data[i+2] == white_pixel) 
            {
                ball_detected=true;
                ballposition = (i % img.step);    
                //ROS_INFO("ball detected =  %d",i);
                //ROS_INFO("position = %d",ballposition);
                //ROS_INFO("left = %d \n",left);
            }
            
    }
    
    if (ball_detected)        
    {
        if  (ballposition > 0 && ballposition < left)
        {
            ROS_INFO("Moving Left");      
            drive_robot(0.3,0.5);
            
        }
    
        if  (ballposition > left && ballposition < center )
        {
            ROS_INFO("Moving straight"); 
            drive_robot(0.5,0.0);
                        
        }
                    
        if  (ballposition > center && ballposition < right )
        {
            ROS_INFO("Moving right"); 
            drive_robot(0.3,-0.5);
            
        }
    }      
    else drive_robot(0.0,0.0);
            
    
}
         

int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");
  

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);
    
    // Handle ROS communication events
    ros::spin();

    return 0;
}
