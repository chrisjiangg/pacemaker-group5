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
    <h1>Date and Time</h1>
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
        <input id="button" type="submit" value="Sign Up">
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
        date_default_timezone_set("America/New_York");
        echo "The current time is " . date("h:i:sa");
        echo "<br>";
        $d=mktime( $hour, $minute, $second, $month, $day, $year);
        echo "Changed date is " . date("Y-m-d h:i:sa", $d);
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