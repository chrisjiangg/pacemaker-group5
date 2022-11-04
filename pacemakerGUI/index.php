<?php
session_start();
    
    include("connection.php");
    include("functions.php");
    //checks if user is logged in if not it redirects the user
    $user_data = check_login($con);
?>

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
    <title>Pacemaker</title>
</head>
<body>
    <!-- css styling -->
    <style type="text/css">
    body {
        background: linear-gradient(to right, white, #7A003C, #56002a);
    }
    </style>
    <h1>Welcome!</h1>
    Hello, <?php echo $user_data['user_name'];?>!
    <br>
    <!-- serial number form -->
    <h2>Serial Number</h2>
    <form method="post">
        <input id="text" type="text" placeholder="Serial Number" name="serial_number" required>
        <input type="submit">
    </form>
    <?php
    if($_SERVER['REQUEST_METHOD'] == "POST"){
        //something was posted stored into variables
        $serial_number = $_POST["serial_number"];
        $_SESSION["serial"]=$serial_number;
        // echo $_SESSION["serial"];
        //goes to index2.php when the serial number entered matches the one in the database
        if($serial_number==$user_data['Serial_number']){
            header("Location: index2.php");
            die;
        }
        else{
            echo "<br>";
            echo "Pacemaker with serial number ".$serial_number." is not attached to this user!";
            echo "<br>";
            echo "Please enter the correct serial number that is attached to the user ".$user_data['user_name']."!";
        }
    }
    ?>
    
</body>
</html>