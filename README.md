# Project2_Simple Ball Following Robot in ROS.
This project uses a differential drive robot built using URDF (Unified Robot Descriptio) file format and housed inside a Gazebo world.
The project contain two C++ ROS nodes that interact with the robot and make it chase a white-colored ball. 

## Directory structure 
```
.Project2                              # Simple Ball Following Robot in ROS
    ├── my_robot                       # my_robot package                   
    │   ├── launch                     # launch folder for launch files   
    │   │   ├── robot_description.launch
    │   │   ├── world.launch
    │   ├── meshes                     # meshes folder for sensors
    │   │   ├── hokuyo.dae
    │   ├── urdf                       # urdf folder for xarco files
    │   │   ├── my_robot.gazebo
    │   │   ├── my_robot.xacro
    │   ├── world                      # world folder for world files
    │   │   ├── myworld2.world
    │   ├── CMakeLists.txt             # compiler instructions
    │   ├── package.xml                # package info
    ├── ball_chaser                    # ball_chaser package                   
    │   ├── launch                     # launch folder for launch files   
    │   │   ├── ball_chaser.launch
    │   ├── src                        # source folder for C++ scripts
    │   │   ├── drive_bot.cpp
    │   │   ├── process_images.cpp
    │   ├── srv                        # service folder for ROS services
    │   │   ├── DriveToTarget.srv
    │   ├── CMakeLists.txt             # compiler instructions
    │   ├── package.xml                # package info               
   ```



![Peek_2022-07-12_05-27](https://github.com/Bebil-P/Project2_SimpleBallFollowingRobot_ROS/assets/109389468/5d691cf5-dab3-43c8-b3a7-ff8ffae44b4e)
