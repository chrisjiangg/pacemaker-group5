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
    <title>AAI</title>
</head>
<body>
    <h1>AAI</h1>
    <h2>Parameters</h2>
    <form method="post">
        <input type="number" name="lower_rate_limit" placeholder="Lower Rate Limit" required>
        <br>
        <br>
        <input type="number" name="upper_rate_limit" placeholder="Upper Rate Limit" required>
        <br>
        <br>
        <input type="number" name="atrial_amplitude" placeholder="Atrial Amplitude" required>
        <br>
        <br>
        <input type="number" name="atrial_pulse_width" placeholder="Atrial Pulse Width" required>
        <br>
        <br>
        <input type="number" name="ventricular_amplitude" placeholder="Ventricular Amplitude" required>
        <br>
        <br>
        <input type="number" name="ventricular_pulse_width" placeholder="Ventricular Pulse Width" required>
        <br>
        <br>
        <input type="number" name="vrp" placeholder="VRP" required>
        <br>
        <br>
        <input type="number" name="arp" placeholder="ARP" required>
        <br>
        <br>
        <input type="submit">
        <br>
        <br>
    </form>
    <?php
    if($_SERVER['REQUEST_METHOD'] == "POST"){
        //something was posted
        $lower_rate_limit = $_POST["lower_rate_limit"];
        $upper_rate_limit = $_POST["upper_rate_limit"];
        $atrial_amplitude = $_POST["atrial_amplitude"];
        $atrial_pulse_width = $_POST["atrial_pulse_width"];
        $ventricular_amplitude = $_POST["ventricular_amplitude"];
        $ventricular_pulse_width = $_POST["ventricular_pulse_width"];
        $vrp = $_POST["vrp"];
        $arp = $_POST["arp"];
        echo "Lower Rate Limit: " . $lower_rate_limit;
        echo "<br>";
        echo "Upper Rate Limit: " . $upper_rate_limit;
        echo "<br>";
        echo "Atrial Amplitude: " . $atrial_amplitude;
        echo "<br>";
        echo "Atrial Pulse Width: " . $atrial_pulse_width;
        echo "<br>";
        echo "Ventrical Amplitude: " . $ventricular_amplitude;
        echo "<br>";
        echo "Ventrical Pulse Width: " . $ventricular_pulse_width;
        echo "<br>";
        echo "VRP: " . $vrp;
        echo "<br>";
        echo "ARP: " . $arp;
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