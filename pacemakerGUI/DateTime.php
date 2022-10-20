<?php
session_start();
    
    include("connection.php");
    include("functions.php");
    //checks if user is logged in if not it redirects the user
    $user_data = check_login($con);
?>

<!DOCTYPE html>
<html>
<head>
    <title>Date and Time</title>
</head>
<body>
    <style type="text/css">
    body {
        background: linear-gradient(to right, white, #7A003C, #56002a);
    }
    </style>
    <h2>Current Date and Time</h2>
    <?php
    date_default_timezone_set("America/New_York");
    echo "Current Date: " . date("Y-m-d");
    echo "<br>";
    echo "Current Time: " . date("h:i:sa");
    echo "<br>";
    ?>
    <h2>Change Date and Time</h2>
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
        //something was posted
        $hour = $_POST["hour"];
        $minute = $_POST["minute"];
        $second = $_POST["second"];
        $month = $_POST["month"];
        $day = $_POST["day"];
        $year = $_POST["year"];
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