# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

In this project we use the PID controller to manoeuvre the vehicle around the lake track in the udacity simulator for term 2 of self driving car nanodegree program. 

**1. Effect of P,I,D components**
* P is the component that is proportional to the current track error(cte). It directly impacts the trajectory of the car as it makes the car to correct in the same ratio of current error in the opposite direction.
* D is the temporal derivative which is used to cancel the effect of overshoot when the vehicle tries to align itself on the track in order to reduce the current track error. 
* I is the integral control which measures all the past values cte and measures the integral or sum of all the crosstrack errors overtimes. It is used to remove initial bias incorrectness. 


**2. Hyperparameters tuning**

* I used manual tuning to optimize my parameters and reduce the cross track error. The car henceforth was able to drive safely around the track without going out of the road. 
