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
    <title>VVI</title>
</head>
<body>
    <!-- css styling -->
    <style type="text/css">
    body {
        background: linear-gradient(to right, white, #7A003C, #56002a);
    }
    </style>
    <h1>VVI</h1>
    <h2>Current Parameters</h2>
    <?php
        //gets user data
        $lower_rate_limit = $user_data['lower_rate_limit'];
        $upper_rate_limit = $user_data['upper_rate_limit'];
        $ventricular_amplitude = $user_data['ventrical_amplitude'];
        $ventricular_pulse_width = $user_data['ventrical_pulse_width'];
        $ventricular_sensitivity = $user_data['ventrical_sensitivity'];
        $vrp = $user_data['vrp'];
        $hysteresis = $user_data['hysteresis'];
        $rate_smoothing = $user_data['rate_smoothing'];
        $mode = $user_data['mode'];

        //printing out values to the screen
        echo "Mode: " . $mode;
        echo "<br>";
        echo "Lower Rate Limit: " . $lower_rate_limit;
        echo "<br>";
        echo "Upper Rate Limit: " . $upper_rate_limit;
        echo "<br>";
        echo "Atrial Amplitude: " . $ventricular_amplitude;
        echo "<br>";
        echo "Atrial Pulse Width: " . $ventricular_pulse_width;
        echo "<br>";
        echo "Atrial Sensitivity: " . $ventricular_sensitivity;
        echo "<br>";
        echo "VRP: " . $vrp;
        echo "<br>";
        echo "Hysteresis: " . $hysteresis;
        echo "<br>";
        echo "Rate Smoothing: " . $rate_smoothing;
        echo "<br>";
    ?>
    <br>
    <a href="VVI.php"><button>Update</button></a>
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
            Ventricular Amplitude (V): <input type="range" name="ventricular_amplitude" placeholder="Ventricular Amplitude" min= "0" max = "5" step= "0.1" value="0" oninput="rangeValue2.innerText = this.value" required>
            <br>
            <p id="rangeValue2">0</p>  
            Ventricular Pulse Width (ms): <input type="range" name="ventricular_pulse_width" placeholder="Ventricular Pulse Width" min= "1" max = "30" step= "1" value="1" oninput="rangeValue3.innerText = this.value" required>
            <br>
            <p id="rangeValue3">1</p>
            Ventricular Sensitivity (V): <input type="range" name="ventricular_sensitivity" placeholder="Ventricular Sensitivity" min="0" max="5" value="0" step="0.1" oninput="rangeValue4.innerText=this.value" required>
            <br>
            <p id="rangeValue4">0</p>
            VRP (ms): <input type="range" name="vrp" placeholder="VRP" min= "150" max = "500" step= "1" value="150" oninput="rangeValue5.innerText = this.value" required>
            <br>
            <p id="rangeValue5">150</p>
            Hysteresis (ppm): <input type="range" name="hysteresis" placeholder="Hysteresis" min = "0" max = "175" step= "1" value="0" oninput="rangeValue7.innerText = this.value" required>
            <br>
            <p id="rangeValue7">0</p>
            Rate Smoothing (%): <input type="range" name="rate_smoothing" placeholder= "Rate Smoothing" min="0" max="25" step="1" value="0" oninput="rangeValue8.innerText = this.value" required>
            <br>
            <p id="rangeValue8">0</p>
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
        $ventricular_sensitivity = $_POST["ventricular_sensitivity"];
        $vrp = $_POST["vrp"];
        $hysteresis = $_POST["hysteresis"];
        $rate_smoothing = $_POST["rate_smoothing"];
        $serial = $_SESSION["serial"];
        $zero = 0;
        $mode = 4;

        if($upper_rate_limit>$lower_rate_limit){
        
        $query = "UPDATE users SET lower_rate_limit='$lower_rate_limit', upper_rate_limit='$upper_rate_limit', mode='$mode', atrial_amplitude='$zero', atrial_pulse_width='$zero', atrial_sensitivity='$zero', ventrical_amplitude='$ventricular_amplitude', ventrical_pulse_width='$ventricular_pulse_width', ventrical_sensitivity='$ventricular_sensitivity', arp='$zero', vrp='$vrp', pvarp='$zero', hysteresis='$hysteresis', rate_smoothing='$rate_smoothing' WHERE Serial_number='$serial'";
        
        mysqli_query($con, $query);
        
       //-----------------Outputing to file and triggering the python script----------------------------------------------------
       exporting_to_file(); //exports only the user in session's data to text file 
       $command = escapeshellcmd('python data.py');
       $output = shell_exec($command);
       echo $output;
       //-----------------END----------------------------------------------------

        //printing out values to the screen
        echo "Mode (VVI): " . $mode;
        echo "<br>";
        echo "Lower Rate Limit: " . $lower_rate_limit;
        echo "<br>";
        echo "Upper Rate Limit: " . $upper_rate_limit;
        echo "<br>";
        echo "Ventricular Amplitude: " . $ventricular_amplitude;
        echo "<br>";
        echo "Ventricular Pulse Width: " . $ventricular_pulse_width;
        echo "<br>";
        echo "Ventricular Sensitivity: " . $ventricular_sensitivity;
        echo "<br>";
        echo "VRP: " . $vrp;
        echo "<br>";
        echo "Hysteresis: " . $hysteresis;
        echo "<br>";
        echo "Rate Smoothing: " . $rate_smoothing;
        echo "<br>";}

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