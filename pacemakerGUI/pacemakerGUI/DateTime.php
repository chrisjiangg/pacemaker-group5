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
    <title>Date and Time</title>
</head>
<body>
    <!-- css styling -->
    <style type="text/css">
    body {
        background: linear-gradient(to right, white, #7A003C, #56002a);
    }
    </style>
    <h2>Current Date and Time</h2>
    <?php
    //displays current date and time
    date_default_timezone_set("America/New_York");
    echo "Current Date: " . date("Y-m-d");
    echo "<br>";
    echo "Current Time: " . date("h:i:sa");
    echo "<br>";
    ?>
    <h2>Change Date and Time</h2>
    <!-- form to change the date and time -->
    <form method="post">
        <input type="number" name="hour" placeholder="Hour (24 hour clock)" required>
        <br>
        <br>
        <input type="number" name="minute" placeholder="Minute" required>
        <br>
        <br>
        <input type="number" name="second" placeholder="Second" required>
        <br>
        <br>
        <input type="number" name="month" placeholder="Month" required>
        <br>
        <br>
        <input type="number" name="day" placeholder="Day" required>
        <br>
        <br>
        <input type="number" name="year" placeholder="Year" required>
        <br>
        <br>
        <input type="submit">
        <br>
        <br>
    </form>
    <?php
    if($_SERVER['REQUEST_METHOD'] == "POST"){
        //something was posted and stores user input into variables
        $hour = $_POST["hour"];
        $minute = $_POST["minute"];
        $second = $_POST["second"];
        $month = $_POST["month"];
        $day = $_POST["day"];
        $year = $_POST["year"];
        //displays inputed date and time
        $datetime=mktime( $hour, $minute, $second, $month, $day, $year);
        echo "Changed Date and Time: " . date("Y-m-d h:i:sa", $datetime);
        echo "<br>";
    }
    ?>
    <br>
    <a href="index.php"><button>Go Back</button></a>
    <br>
    <br>
    <a href="logout.php">Logout</a>
</body>
</html>