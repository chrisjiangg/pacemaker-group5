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
    <title>VOOR</title>
</head>
<body>
    <!-- css styling -->
    <style type="text/css">
    body {
        background: linear-gradient(to right, white, #7A003C, #56002a);
    }
    </style>
    <h1>VOOR</h1>
    <h2>Current Parameters</h2>
    <?php
        //gets user data
        $lower_rate_limit = $user_data['lower_rate_limit'];
        $upper_rate_limit = $user_data['upper_rate_limit'];
        $ventricular_amplitude = $user_data['ventrical_amplitude'];
        $ventricular_pulse_width = $user_data['ventrical_pulse_width'];
        $maximum_sensor_rate = $user_data["maximum_sensor_rate"];
        $reaction_time = $user_data["reaction_time"];
        $response_factor = $user_data["response_factor"];
        $activity_threshold = $user_data["activity_threshold"];
        $recovery_time = $user_data["recovery_time"];
        $mode = $user_data["mode"];

        //printing out values to the screen
        echo "Mode: " . $mode;
        echo "<br>";
        echo "Lower Rate Limit: " . $lower_rate_limit;
        echo "<br>";
        echo "Upper Rate Limit: " . $upper_rate_limit;
        echo "<br>";
        echo "ventricular Amplitude: " . $ventricular_amplitude;
        echo "<br>";
        echo "ventricular Pulse Width: " . $ventricular_pulse_width;
        echo "<br>";
        echo "Maximum Sensor Rate: " . $maximum_sensor_rate;
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
    <a href="VOOR.php"><button>Update</button></a>
    <br>
    <h2>Change Parameters</h2>
        <!-- sliders -->
        <form method="post">
            Lower Rate Limit (ppm): <input type="range" name="lower_rate_limit" placeholder="Lower Rate Limit" min = "30" max = "175" step= "1" value="30" oninput="rangeValue.innerText = this.value" required>
            <br>
            <p id="rangeValue">30</p>  
            Upper Rate Limit (ppm): <input type="range" name="upper_rate_limit" placeholder="Upper Rate Limit" min = "50" max = "175" step= "1" value="50" oninput="rangeValue1.innerText = this.value" required>
            <br>
            <p id="rangeValue1">50</p>
            Maximum Sensor Rate (ppm): <input type="range" name="maximum_sensor_rate" placeholder= "Maximum Sensing Rate" min="50" max="175" step="1" value="50" oninput="rangeValue9.innerText = this.value" required>
            <br>
            <p id="rangeValue9">50</p> 
            Ventricular Amplitude (V): <input type="range" name="ventricular_amplitude" placeholder="Ventricular Amplitude" min= "0" max = "5" step= "0.1" value="0" oninput="rangeValue2.innerText = this.value" required>
            <br>
            <p id="rangeValue2">0</p>  
            Ventricular Pulse Width (ms): <input type="range" name="ventricular_pulse_width" placeholder="Ventricular Pulse Width" min= "1" max = "30" step= "1" value="1" oninput="rangeValue3.innerText = this.value" required>
            <br>
            <!-- added -->
            <p id="rangeValue8">1</p>  
            Activity Threshold (V-Low=1, Low=2, Med-Low=3, Med=4, Med-High=5, High=6, V-High=7): <input type="range" name="activity_threshold" placeholder= "Activity Threshold" min="1" max="7" step="1" value="1" oninput="rangeValue10.innerText = this.value" required>
            <br>
            <p id="rangeValue10">1</p> 
            Reaction Time (sec): <input type="range" name="reaction_time" placeholder= "Reaction Time" min="10" max="50" step="1" value="10" oninput="rangeValue11.innerText = this.value" required>
            <br>
            <p id="rangeValue11">10</p> 
            Response Factor: <input type="range" name="response_factor" placeholder= "Response Factor" min="1" max="16" step="1" value="1" oninput="rangeValue12.innerText = this.value" required>
            <br>
            <p id="rangeValue12">1</p> 
            Recovery Time (min): <input type="range" name="recovery_time" placeholder= "Recovery Time" min="2" max="16" step="1" value="2" oninput="rangeValue13.innerText = this.value" required>
            <br>
            <!-- Done Adding -->
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
        $ventricular_amplitude = $_POST["ventricular_amplitude"];
        $ventricular_pulse_width = $_POST["ventricular_pulse_width"];
        $maximum_sensor_rate = $_POST["maximum_sensor_rate"];
        $reaction_time = $_POST["reaction_time"];
        $response_factor = $_POST["response_factor"];
        $activity_threshold = $_POST["activity_threshold"];
        $recovery_time = $_POST["recovery_time"];
        $serial = $_SESSION["serial"];
        $zero = 0;
        $mode = 6;

        if($upper_rate_limit>$lower_rate_limit){
        
        $query = "UPDATE users SET lower_rate_limit='$lower_rate_limit', upper_rate_limit='$upper_rate_limit', mode='$mode', maximum_sensor_rate='$maximum_sensor_rate', atrial_amplitude='$zero', atrial_pulse_width='$zero', atrial_sensitivity='$zero', ventrical_amplitude='$ventricular_amplitude', ventrical_pulse_width='$ventricular_pulse_width', ventrical_sensitivity='$zero', arp='$zero', vrp='$zero', pvarp='$zero', hysteresis='$zero', rate_smoothing='$zero', activity_threshold='$activity_threshold', reaction_time='$reaction_time', response_factor='$response_factor', recovery_time='$recovery_time' WHERE Serial_number='$serial'";
        mysqli_query($con, $query);

       //-----------------Outputing to file and triggering the python script----------------------------------------------------
       exporting_to_file(); //exports only the user in session's data to text file 
       $command = escapeshellcmd('python data.py');
       $output = shell_exec($command);
       echo $output;
       //-----------------END----------------------------------------------------

        //printing out values to the screen
        echo "Mode (VOOR): " . $mode;
        echo "<br>";
        echo "Lower Rate Limit: " . $lower_rate_limit;
        echo "<br>";
        echo "Upper Rate Limit: " . $upper_rate_limit;
        echo "<br>";
        echo "Maximum Sensor Rate: " . $maximum_sensor_rate;
        echo "<br>";
        echo "Ventricular Amplitude: " . $ventricular_amplitude;
        echo "<br>";
        echo "Ventricular Pulse Width: " . $ventricular_pulse_width;
        echo "<br>";
        echo "Maximum Sensing Rate: " . $maximum_sensor_rate;
        echo "<br>";
        echo "Reaction Time: " . $reaction_time;
        echo "<br>";
        echo "Response Factor: " . $response_factor;
        echo "<br>";
        echo "Activity Threshold: " . $activity_threshold;
        echo "<br>";
        echo "Recovery Time: " . $recovery_time;
        echo "<br>";
    
    }

        else{echo '<script>alert("lower limit can not exceed upper limit!")</script>'; }

    }
    ?>
    <br>
    <a href="index2.php"><button>Go Back</button></a>
    <br>
    <br>
    <a href="logout.php">Logout</a>
</body>
</html>