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
    <title>VOO</title>
</head>
<body>
    <style type="text/css">
    body {
        background: linear-gradient(to right, white, #7A003C, #56002a);
    }
    </style>
    <h1>VOO</h1>
    <h2>Current Parameters</h2>
    <?php
        //gets user data
        $lower_rate_limit = $user_data['lower_rate_limit'];
        $upper_rate_limit = $user_data['upper_rate_limit'];
        $ventricular_amplitude = $user_data['ventrical_amplitude'];
        $ventricular_pulse_width =  $user_data['ventrical_pulse_width'];
        //printing out values to the screen
        echo "Lower Rate Limit: " . $lower_rate_limit;
        echo "<br>";
        echo "Upper Rate Limit: " . $upper_rate_limit;
        echo "<br>";
        echo "Ventrical Amplitude: " . $ventricular_amplitude;
        echo "<br>";
        echo "Ventrical Pulse Width: " . $ventricular_pulse_width;
        echo "<br>";
    ?>
    <h2>Change Parameters</h2>
        <form method="post">
            Lower Rate Limit (ppm): <input type="range" name="lower_rate_limit" placeholder="Lower Rate Limit" min = "30" max = "175" step= "1" value="30" oninput="rangeValue.innerText = this.value" required>
            <br>
            <p id="rangeValue">30</p>  
            Upper Rate Limit (ppm): <input type="range" name="upper_rate_limit" placeholder="Upper Rate Limit" min = "50.0" max = "175.0" step= "5" value="50" oninput="rangeValue1.innerText = this.value" required>
            <br>
            <p id="rangeValue1">50</p>  
            Ventricular Amplitude (V): <input type="range" name="ventricular_amplitude" placeholder="Ventricular Amplitude" min= "0" max = "7" step= "0.1" value="0" oninput="rangeValue4.innerText = this.value" required>
            <br>
            <p id="rangeValue4">0</p> 
            Ventricular Pulse Width (ms): <input type="range" name="ventricular_pulse_width" placeholder="Ventricular Pulse Width" min= "0.05" max = "1.9" step= "0.05" value="0.05" oninput="rangeValue5.innerText = this.value" required>
            <br>
            <p id="rangeValue5">0.05</p>
            <input type="submit">
            <br>
            <br>
        </form>
    <h2>Changed Parameters</h2>
    <?php
    if($_SERVER['REQUEST_METHOD'] == "POST"){
        //something was posted stored into variables
        $lower_rate_limit = $_POST["lower_rate_limit"];
        $upper_rate_limit = $_POST["upper_rate_limit"];
        $ventricular_amplitude = $_POST["ventricular_amplitude"];
        $ventricular_pulse_width = $_POST["ventricular_pulse_width"];
        $serial = $_SESSION["serial"];
        $zero = 0;

        if ($upper_rate_limit> $lower_rate_limit){
        $query = "UPDATE users SET lower_rate_limit='$lower_rate_limit', upper_rate_limit='$upper_rate_limit', atrial_amplitude='$zero', atrial_pulse_width='$zero', atrial_sensitivity='$zero', ventrical_amplitude='$ventricular_amplitude', ventrical_pulse_width='$ventricular_pulse_width', ventrical_sensitivity='$zero', arp='$zero', vrp='$zero', pvarp='$zero', hysteresis='$zero', rate_smoothing='$zero' WHERE Serial_number='$serial'";
        mysqli_query($con, $query);
        //printing out values to the screen
        echo "Lower Rate Limit: " . $lower_rate_limit;
        echo "<br>";
        echo "Upper Rate Limit: " . $upper_rate_limit;
        echo "<br>";
        echo "Ventrical Amplitude: " . $ventricular_amplitude;
        echo "<br>";
        echo "Ventrical Pulse Width: " . $ventricular_pulse_width;
        echo "<br>";
    
        }

        else{
            echo '<script>alert("lower limit can not exceed upper limit!")</script>';
        }
       
    }
    ?>
    <br>
    <a href="index2.php"><button>Go Back</button></a>
    <br>
    <br>
    <a href="logout.php">Logout</a>
</body>
</html>