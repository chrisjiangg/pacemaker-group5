<?php
session_start();
    
include("connection.php");
include("functions.php");

if($_SERVER['REQUEST_METHOD'] == "POST"){
    //something was posted
    $user_name = $_POST['user_name'];
    $password = $_POST['password'];

    if(!empty($user_name) && !empty($password) && !is_numeric($user_name)){
        //read from database
        $query = "select * from users where user_name = '$user_name' limit 1";
        $result = mysqli_query($con, $query);
        if($result){
            if($result && mysqli_num_rows($result) > 0){
                //returns users data
                $user_data = mysqli_fetch_assoc($result);
                //checks if password in database is the same password as the user gave
                if($user_data['password'] === $password){
                    $_SESSION['user_id'] = $user_data['user_id'];
                    header("Location: index.php");
                    die;
                }
            }
        }
        echo '<script>alert("Wrong username or password")</script>';
    }
    else{
        echo '<script>alert("Wrong username or password")</script>';
    }
}

?>

<!DOCTYPE html>
<html>
<head>
    <title>Login</title>
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
    }

    #button{
        padding: 10px;
        width: 100px;
        color: white;
        background-color: grey;
        text-align: center;
        border: none;
        z-index: 2;
    }

    #box{
        background-color: #7A003C;
        margin: auto;
        width: 250px;
        text-align: center;
        padding: 25px;
        z-index: 2;
    }
    </style>
    <div id="box">
        <form method="post">
            <div style="font-size: 25px;margin: 10px;color: white;"><strong>Login</strong></div>

            <input id="text" type="text" placeholder="Username" name="user_name" required><br><br>
            <input id="text" type="password" placeholder="Password" name="password" required><br><br>

            <input id="button" type="submit" value="Sign In"><br><br>
            <!--allows to go to the signup page-->
            <a href="signup.php" style="color: white;">Don't have an account?</a><br><br>
        </form>
    </div>
</body>
</html>