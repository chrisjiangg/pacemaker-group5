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
    <title>AAI</title>
</head>
<body>
    <!-- css styling -->
    <style type="text/css">
    body {
        background: linear-gradient(to right, white, #7A003C, #56002a);
    }
    </style>
    <h1>AAI</h1>
    <h2>Current Parameters</h2>
    <?php
        //gets user data
        $lower_rate_limit = $user_data['lower_rate_limit'];
        $upper_rate_limit = $user_data['upper_rate_limit'];
        $atrial_amplitude = $user_data['atrial_amplitude'];
        $atrial_pulse_width = $user_data['atrial_pulse_width'];
        $atrial_sensitivity = $user_data['atrial_sensitivity'];
        $arp = $user_data['arp'];
        $pvarp = $user_data['pvarp'];
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
    ?>
    <br>
    <a href="AAI.php"><button>Update</button></a>
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
            Atrial Amplitude (V): <input type="range" name="atrial_amplitude" placeholder="Atrial Amplitude" min= "0" max = "5" step= "0.1" value="0" oninput="rangeValue2.innerText = this.value" required>
            <br>
            <p id="rangeValue2">0</p>  
            Atrial Pulse Width (ms): <input type="range" name="atrial_pulse_width" placeholder="Atrial Pulse Width" min= "1" max = "30" step= "1" value="1" oninput="rangeValue3.innerText = this.value" required>
            <br>
            <p id="rangeValue3">1</p>
            Atrial Sensitivity (V): <input type="range" name="atrial_sensitivity" placeholder="Atrial Sensitivity" min="0" max="5" value="0" step="0.1" oninput="rangeValue4.innerText=this.value" required>
            <br>
            <p id="rangeValue4">0</p>
            ARP (ms): <input type="range" name="arp" placeholder="ARP" min= "150" max = "500" step= "1" value="150" oninput="rangeValue5.innerText = this.value" required>
            <br>
            <p id="rangeValue5">150</p>
            PVARP (ms): <input type="range" name="pvarp" placeholder="PVARP" min= "150" max = "500" step= "1" value="150" oninput="rangeValue6.innerText = this.value" required>
            <br>
            <p id="rangeValue6">150</p>
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
        $atrial_amplitude = $_POST["atrial_amplitude"];
        $atrial_pulse_width = $_POST["atrial_pulse_width"];
        $atrial_sensitivity = $_POST["atrial_sensitivity"];
        $arp = $_POST["arp"];
        $pvarp = $_POST["pvarp"];
        $hysteresis = $_POST["hysteresis"];
        $rate_smoothing = $_POST["rate_smoothing"];
        $serial = $_SESSION["serial"];
        $zero = 0;
        $mode = 5;

        if($upper_rate_limit>$lower_rate_limit && $atrial_sensitivity >=2.6 && $atrial_sensitivity!=5.0 && (((60000/$lower_rate_limit)-$atrial_pulse_width-$arp)>0)){
        $query = "UPDATE users SET lower_rate_limit='$lower_rate_limit', upper_rate_limit='$upper_rate_limit', mode='$mode', maximum_sensor_rate='$zero', atrial_amplitude='$atrial_amplitude', atrial_pulse_width='$atrial_pulse_width', atrial_sensitivity='$atrial_sensitivity', ventrical_amplitude='$zero', ventrical_pulse_width='$zero', ventrical_sensitivity='$zero', arp='$arp', vrp='$zero', pvarp='$pvarp', hysteresis='$hysteresis', rate_smoothing='$rate_smoothing', activity_threshold='$zero', reaction_time='$zero', response_factor='$zero', recovery_time='$zero' WHERE Serial_number='$serial'";
        mysqli_query($con, $query);
        
        //-----------------Outputing to file and triggering the python script----------------------------------------------------
        exporting_to_file(); //exports only the user in session's data to text file 
        $command = escapeshellcmd('python data.py');
        $output = shell_exec($command);
        echo $output;
        //-----------------END----------------------------------------------------

        //printing out values to the screen
        echo "Mode (AAI): " . $mode;
        echo "<br>";
        echo "Lower Rate Limit: " . $lower_rate_limit;
        echo "<br>";
        echo "Upper Rate Limit: " . $upper_rate_limit;
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
        echo "<br>"; }

        else{echo '<script>alert("USER ENTERED PARAMETERS CAUSE ERRORS!")</script>';}
    }
    ?>
    <br>
    <a href="graph2.php" target = "_blank"><button>Show graph 2</button></a>
    <br>
    <br>
    <a href="graph.php" target = "_blank"><button>Show graph 1</button></a>
    <br>
    <br>
    <a href="index2.php"><button>Go Back</button></a>
    <br>
    <br>
    <a href="logout.php">Logout</a>
</body>
</html>