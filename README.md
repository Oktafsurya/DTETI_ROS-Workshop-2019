# DTETI_ROS-Workshop-2019
## Requirements
to run all demo in this repository, you need:
+ ROS Kinetic
+ Husky Robot Simulator
+ RVIZ
+ Gazebo_ros_pkgs
+ catkin-pkg

## Week 1
In the week 1, we learn about ROS basic concept like: create new workspace, package using some common dependencies, create a node with custom topic, message and service, and create launch file. You can see all files for week 1 on the **ros_demo** folder.

to run one node:
```bash
$ cd your_workspace
$ roscore
$ rosrun ros_demo demo_msg_publisher
$ rosrun ros_demo demo_msg_subscriber
```
or to run multiple node at once using launch file:
```bash
$ cd your_workspace
$ roslaunch ros_demo demo_msg.launch
```

## Week 2
In the week 2, we learn more about how ROS communicating and sending data between nodes. To do this we will use simulator (turtlesim and Husky Robot Simulator) and create our own publisher & subscriber node to handle that simulator. 

### working with turtlesim
We want to move the turtle icon on turtlesim, so we create publisher node that will send random velocity and then the turtle icon will move according to the velocity we have given. After this we create a subscriber node that will read the position of turtle icon and display it in the terminal. All files for week 2 (working with turtlesim) on the **turtlesim_demo** folder.

to run this demo:
```bash
$ cd your_workspace
$ roscore
$ rosrun turtlesim turtlesim_node
$ rosrun turtlesim_demo velocity_publisher
$ rosrun turtlesim_demo pose_subscriber
```

<p align="center"> 
<img src="https://github.com/Oktafsurya/DTETI_ROS-Workshop-2019/blob/master/demo.gif">
</p>

### working with Husky Robot Simulator
We will create a subscriber node and read distance from ```/scan``` topic and display the reading result from husky laser sensor on RVIZ. 
The main files for this demo is on **husky_highlevel_controller** folder. 

to run this demo:
```bash
$ cd your_workspace
$ roslaunch husky_highlevel_controller husky_test.launch
```
to view reading result from husky laser sensor on RVIZ:
+ add some obstacles in husky gazebo
+ open RVIZ and change the Fixed Frame to **odom**
+ Add (By topic) and choose ```/scan``` topic -> LaserScan

<p align="center"> 
<img width="600" height="350" src="https://github.com/Oktafsurya/DTETI_ROS-Workshop-2019/blob/master/laser.png">
</p>







