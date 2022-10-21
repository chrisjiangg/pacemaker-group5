<?php
session_start();
    
    include("connection.php");
    include("functions.php");

    if($_SERVER['REQUEST_METHOD'] == "POST"){
        //something was posted
        $user_name = $_POST['user_name'];
        $password = $_POST['password'];
        $Serial_number = $_POST['serial_number'];
        $sql = "SELECT * from users";
        if($result = mysqli_query($con,$sql)){
            $usercount=mysqli_num_rows($result);
        }
        if(!empty($user_name) && !empty($password) && !empty($Serial_number) &&  !is_numeric($user_name)){
            if($usercount<10){
                //save to database
                $user_id = random_num(10);
                $query = "insert into users (user_id,user_name,password,serial_number) values ('$user_id','$user_name','$password','$Serial_number')";
                mysqli_query($con, $query);
                //redirects user to login page
                header("Location: login.php");
                die;
            }
            else{
                echo '<script>alert("Maximum of 10 Users Reached!")</script>';
            }
        }
    }

?>
<!--File type-->
<!DOCTYPE html>
<!--Sets Language-->
<html lang="en">
<head>
    <!--Specifies the character encoding-->
    <!--UTF-8 covers most of the characters and symbols-->
    <meta charset="UTF-8">
    <!--http-equiv provides an HTTP header for the value of the content attribute and content specifies the value associated with the http-equiv or name attribute-->
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <!--Specifies a name for the metadata-->
    <!--Sets the viewport and makes it look good on all devices-->
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <!--Name of the tab-->
    <title>Sign Up</title>
</head>
<body>
    <style type="text/css">
    body{
        background-image: url(./background1.jpg);
        background-size: cover;
        display: flex;
        justify-content: center;
        align-items: center;
        flex-direction: column;
        font-family: 'Montserrat', sans-serif;
        min-height: 100vh;
        margin: -20px 0 50px;
        z-index: 1;
    }
    #text{
        height: 25px;
        border-radius: 5px;
        padding: 4px;
        border: solid thin #fff;
        width: 100%;
        z-index: 2;
    }

    #button{
        padding: 10px;
        width: 100px;
        color: white;
        text-align: center;
        background-color: grey;
        border: none;
        z-index: 2;
    }

    #box{
        background-color: #7A003C;
        text-align: center;
        margin: auto;
        width: 250px;
        padding: 25px;
        z-index: 2;
    }
    </style>
    <div id="box">
        <form method="post">
        <div style="font-size: 25px;margin: 10px;color: white;"><strong>Create Account</strong></div>

            <input id="text" type="text" placeholder="Username" name="user_name" required>
            <br>
            <br>
            <input id="text" type="password" placeholder="Password" name="password" required>
            <br>
            <br>
            <input id="text" type="text" placeholder="Serial Number" name="serial_number" required>
            <br>
            <br>
            <input id="button" type="submit" value="Sign Up">
            <br>
            <br>
           
            <!--allows to go to the signup page-->
            <a href="login.php" style="color: white;">Already have an account?</a><br><br>
        </form>
    </div>
</body>
</html>