

About project:
*We have next user types: User, Driver, and Admin
In this program, the User will try the Order taxi service and the Driver will check the available Order that fulfilled the requirements from the user.
Admin has the ability to block some access to app feature or to accept orders for the driver

Remark:
The program creates and takes an object from the Database with the filename "username".txt. 
if the user does not exist, you can enter "yes" on the "register" message to create a database for the new User and similar for Driver
note: the new driver will send a request to admin and iff admin accept the requested driver can get access to the app feature;
I create 2 sample user named "oka" and "heero" and 2 sample Driver named "yuno" and "asuna", ofc you can create as many as you want 

To test the program you should:
1. Install IDE: CLion (c++20)

2. Open the project file

3. Run main.CPP

4. Choose you are login as "User" "Admin" or "Driver"
NOTE: Based on the previous Home Assignment 2 comment, 
I suggested not use the switch, so you should Type/Enter it manually

5. if you choose User(UserType)
 * enter username
 ** choose what you want to do by input int 
(1 for see Order History, 2 for order, 3 for set address and payment)
***to order a taxi, you just need to enter "To"/your destination
   and choose your Car Type by entering a number
NOTE: "From" is already set as User address so if you want to change "From" change the User address

6. if you choose Driver
 * enter name
 ** choose what you want to do by input int 
(1 for see Order History, 2 for Pick available order)

7. if you choose Admin
*enter username(oka)
**enter password(oka123)
*** choose what you want to do by input int 
(1 for Block user access, 2 for open blocked access, 3 for Pick available order for driver, 4 for admitting new driver)
note: if you want to block or unblock a user/driver you should enter the username of the User/Driver

IMPORTANT STEP:
Run Program for booking taxi 

note: because we assume using the app from more than 1 device (as user, driver, or admin)
	the program will exit automatically after doing a certain task and you should
	re-run the program assuming there is the interaction between user, driver, and admin

1. Enter as User to make an order (program will close automatically after making an order)
Re-Run Program
2. Enter as Driver to accept an order (program will close automatically after picking an order)
Re-Run Program
3. Enter as User again
=> if User order accepted by a Driver
	 *Enter a number
	 (1 for Finish (Assume that User Arrived at destination, 2 for check current coordinate)
=> if User order not taken by a Driver
	*Program will Close and you need to log in as a Driver to accept this order
Re-Run Program
4. Enter as Driver
=> if Order finished by User 
	*You can get a rating given by the User and the program will close (Re-Run to get another Order)
=> if Order not finished yet by User
	*Program will Close and you need to log in as a User to Finish this order
5. Done

Best Regard
Made Oka Resia Wedamerta
