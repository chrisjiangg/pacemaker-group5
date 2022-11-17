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
    <title>AAIR</title>
</head>
<body>
    <!-- css styling -->
    <style type="text/css">
    body {
        background: linear-gradient(to right, white, #7A003C, #56002a);
    }
    </style>
    <h1>AAIR</h1>
    <h2>Current Parameters</h2>
    <?php
        //gets user data
        $lower_rate_limit = $user_data['lower_rate_limit'];
        $upper_rate_limit = $user_data['upper_rate_limit'];
        $maximum_sensor_rate = $user_data['maximum_sensor_rate'];
        $atrial_amplitude = $user_data['atrial_amplitude'];
        $atrial_pulse_width = $user_data['atrial_pulse_width'];
        $atrial_sensitivity = $user_data['atrial_sensitivity'];
        $arp = $user_data['arp'];
        $pvarp = $user_data['pvarp'];
        $hysteresis = $user_data['hysteresis'];
        $rate_smoothing = $user_data['rate_smoothing'];
        $activity_threshold = $user_data['activity_threshold'];
        $reaction_time = $user_data['reaction_time'];
        $response_factor = $user_data['response_factor'];
        $recovery_time = $user_data['recovery_time'];
        //printing out values to the screen
        echo "Lower Rate Limit: " . $lower_rate_limit;
        echo "<br>";
        echo "Upper Rate Limit: " . $upper_rate_limit;
        echo "<br>";
        echo "Maximum Sensor Rate: " . $maximum_sensor_rate;
        echo "<br>";
        echo "Atrial Amplitude: " . $atrial_amplitude;
        echo "<br>";
        echo "Atrial Pulse Width: " . $atrial_pulse_width;
        echo "<br>";
        echo "Atrial Sensitivity: " . $atrial_sensitivity;
        echo "<br>";
        echo "ARP: " . $arp;
        echo "<br>";
        echo "PVARP: " . $pvarp;
        echo "<br>";
        echo "Hysteresis: " . $hysteresis;
        echo "<br>";
        echo "Rate Smoothing: " . $rate_smoothing;
        echo "<br>";
        echo "Activity Threshold: " . $activity_threshold;
        echo "<br>";
        echo "Reaction Time: " . $reaction_time;
        echo "<br>";
        echo "Response Factor: " . $response_factor;
        echo "<br>";
        echo "Recovery Time: " . $recovery_time;
        echo "<br>";
    ?>
    <br>
    <a href="AAIR.php"><button>Update</button></a>
    <br>
    <h2>Change Parameters</h2>
        <!-- sliders -->
        <form method="post">
            Lower Rate Limit (ppm): <input type="range" name="lower_rate_limit" placeholder="Lower Rate Limit" min = "30" max = "175" step= "1" value="30" oninput="rangeValue.innerText = this.value" required>
            <br>
            <p id="rangeValue">30</p>  
            Upper Rate Limit (ppm): <input type="range" name="upper_rate_limit" placeholder="Upper Rate Limit" min = "50" max = "175" step= "5" value="50" oninput="rangeValue1.innerText = this.value" required>
            <br>
            <p id="rangeValue1">50</p> 
            Maximum Sensor Rate (ppm): <input type="range" name="upper_rate_limit" placeholder="Upper Rate Limit" min = "50" max = "175" step= "5" value="50" oninput="rangeValue2.innerText = this.value" required>
            <br>
            <p id="rangeValue2">50</p> 
            Atrial Amplitude (V): <input type="range" name="atrial_amplitude" placeholder="Atrial Amplitude" min= "0" max = "7" step= "0.1" value="0" oninput="rangeValue3.innerText = this.value" required>
            <br>
            <p id="rangeValue3">0</p>  
            Atrial Pulse Width (ms): <input type="range" name="atrial_pulse_width" placeholder="Atrial Pulse Width" min= "0.05" max = "1.9" step= "0.05" value="0.05" oninput="rangeValue4.innerText = this.value" required>
            <br>
            <p id="rangeValue4">0.05</p>
            Atrial Sensitivity (mV): <input type="range" name="atrial_sensitivity" placeholder="Atrial Sensitivity" min="0.25" max="10" value="0.25" step="0.25" oninput="rangeValue5.innerText=this.value" required>
            <br>
            <p id="rangeValue5">0.25</p>
            ARP (ms): <input type="range" name="arp" placeholder="ARP" min= "150" max = "500" step= "10" value="150" oninput="rangeValue6.innerText = this.value" required>
            <br>
            <p id="rangeValue6">150</p>
            PVARP (ms): <input type="range" name="pvarp" placeholder="PVARP" min= "150" max = "500" step= "10" value="150" oninput="rangeValue7.innerText = this.value" required>
            <br>
            <p id="rangeValue7">150</p>
            Hysteresis (ppm): <input type="range" name="hysteresis" placeholder="Hysteresis" min = "30" max = "175" step= "1" value="0" oninput="rangeValue8.innerText = this.value" required>
            <br>
            <p id="rangeValue8">0</p>
            Rate Smoothing (%): <input type="range" name="rate_smoothing" placeholder= "Rate Smoothing" min="0" max="25" step="1" value="0" oninput="rangeValue9.innerText = this.value" required>
            <br>
            <p id="rangeValue9">0</p>
            Activity Threshold (V-Low=1, Low=2, Med-Low=3, Med=4, Med-High=5, High=6, V-High=7): <input type="range" name="activity_threshold" placeholder= "Activity Threshold" min="1" max="7" step="1" value="1" oninput="rangeValue10.innerText = this.value" required>
            <br>
            <p id="rangeValue10">1</p>
            Reaction Time (sec): <input type="range" name="reaction_time" placeholder= "Reaction Time" min="10" max="50" step="10" value="10" oninput="rangeValue11.innerText = this.value" required>
            <br>
            <p id="rangeValue11">10</p>
            Response Factor: <input type="range" name="response_factor" placeholder= "Response Factor" min="1" max="16" step="1" value="1" oninput="rangeValue12.innerText = this.value" required>
            <br>
            <p id="rangeValue12">1</p>
            Recovery Time (min): <input type="range" name="recover_time" placeholder= "Recovery Time" min="2" max="16" step="1" value="2" oninput="rangeValue13.innerText = this.value" required>
            <br>
            <p id="rangeValue13">2</p>
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
        $maximum_sensor_rate = $_POST["maximum_sensor_rate"];
        $atrial_amplitude = $_POST["atrial_amplitude"];
        $atrial_pulse_width = $_POST["atrial_pulse_width"];
        $atrial_sensitivity = $_POST["atrial_sensitivity"];
        $arp = $_POST["arp"];
        $pvarp = $_POST["pvarp"];
        $hysteresis = $_POST["hysteresis"];
        $rate_smoothing = $_POST["rate_smoothing"];
        $activity_threshold = $_POST["activity_threshold"];
        $reaction_time = $_POST["reaction_time"];
        $response_factor = $_POST["response_factor"];
        $recovery_time = $_POST["recovery_time"];
        $serial = $_SESSION["serial"];
        $zero = 0;

        if($upper_rate_limit>$lower_rate_limit){
        $query = "UPDATE users SET lower_rate_limit='$lower_rate_limit', upper_rate_limit='$upper_rate_limit', maximum_rate_sensor='$maximum_sensor_rate', atrial_amplitude='$atrial_amplitude', atrial_pulse_width='$atrial_pulse_width', atrial_sensitivity='$atrial_sensitivity', ventrical_amplitude='$zero', ventrical_pulse_width='$zero', ventrical_sensitivity='$zero', arp='$arp', vrp='$zero', pvarp='$pvarp', hysteresis='$hysteresis', rate_smoothing='$rate_smoothing', activity_threshold='$activity_threshold', reaction_time='$reaction_time', response_factor='$response_factor', recovery_time='$recovery_time' WHERE Serial_number='$serial'";
        
        mysqli_query($con, $query);

        //printing out values to the screen
        echo "Lower Rate Limit: " . $lower_rate_limit;
        echo "<br>";
        echo "Upper Rate Limit: " . $upper_rate_limit;
        echo "<br>";
        echo "Maximum Sensor Rate: " . $maximum_sensor_rate;
        echo "<br>";
        echo "Atrial Amplitude: " . $atrial_amplitude;
        echo "<br>";
        echo "Atrial Pulse Width: " . $atrial_pulse_width;
        echo "<br>";
        echo "Atrial Sensitivity: " . $atrial_sensitivity;
        echo "<br>";
        echo "ARP: " . $arp;
        echo "<br>";
        echo "PVARP: " . $pvarp;
        echo "<br>";
        echo "Hysteresis: " . $hysteresis;
        echo "<br>";
        echo "Rate Smoothing: " . $rate_smoothing;
        echo "<br>";
        echo "Activity Threshold: " . $activity_threshold;
        echo "<br>";
        echo "Reaction Time: " . $reaction_time;
        echo "<br>";
        echo "Response Factor: " . $response_factor;
        echo "<br>";
        echo "Recovery Time: " . $recovery_time;
        echo "<br>";
        }

        else{echo '<script>alert("lower limit can not exceed upper limit!")</script>';}
    }
    ?>
    <br>
    <a href="index2.php"><button>Go Back</button></a>
    <br>
    <br>
    <a href="logout.php">Logout</a>
</body>
</html>