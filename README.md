# CarND-Controls-PID
This is the fourth project of SDC term 2, I learned PIT controller which stands for propotional, diffential and integral.
---

# PID description

P is propotional control. The steering angle will be the propotional to cross track error. If p is bigger, it will oscillate faster and make it easier for over-shoot. Below video is only using P control parameter with 0.5.

[link to p.mov](./p.mov)

D is diffential control. When approaching target trajectory, the cross track error becomes smaller and smaller, so that diffentialcontrol is used to count the steers and steer up to make it gracelly approch the target trajectory. This video is the car status after implmented P and D parameter with P 0.5 and D equals 4.

[link to pd.mov](./pd.mov)


I is for integral control, which is the sum of the cross errors over time. So if you have a steering mode leading you far away from the trajectory, in a long term run, it will make sure you get closer to the trajetory. As in this project, if the car went away too far, it won't be back to trajectory. So we just set a very small I value in this project for example 0.005. Here is the car status after implemented PID controller.

[link to pid.mov](./pid.mov)


# Parameter optimization 
I have implemented parameter optimization with twiddle. But if set the PID as all 0 initially, the car won't keep in the trajectory. So we have to manually fine one approximate value for P and D to keep the car with in road. Then use twiddle function to optimize all parameters.

InitiaIly I set P as 0.8 but relized it's too big as the car swings. After that i tried 0.5, 0.4 etc and choosed p as 0.25 which can almost keep the car in the road. After that I tried D parameter with different values and choosed 4. Then I turn on the twiddle function and it suggests a PID with (0.45, 0, 2.5). Then observe the car performace based on how car behaves at corner part and adjust the parameter trivally to (0.23, 0.001, 2.9).

My final parameter is (0.23, 0.001, 2.9). Here is the final video:
[link to final.mov](./final.mov)


# How to build

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 


