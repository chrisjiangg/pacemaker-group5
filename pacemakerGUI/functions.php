<?php
//checks if user is logged in
function check_login($con){
    //check if theres user_id in session
    if(isset($_SESSION['user_id'])){
        $id = $_SESSION['user_id'];
        $query = "select * from users where user_id = '$id' limit 1";

        $result = mysqli_query($con,$query);
        if($result && mysqli_num_rows($result) > 0){
            //returns users data
            $user_data = mysqli_fetch_assoc($result);
            return $user_data;
        }
    }

    //redirect to login
    header("Location: login.php");
    die;
}
//creates unique user id for each user
function random_num($length){
    $text="";
    if($length <5){
        $length =5;
    }
    $len = rand(4,$length);

    for($i=0; $i<$len; $i++){
        $text.= rand(0,9);
    }
    return $text;
}

//checks if local machine is little endian
function isLittleEndian() {
    $testint = 0x00FF;
    $p = pack('S', $testint);
    return $testint===current(unpack('v', $p));
}

function exporting_to_file(){
    $fh = fopen('data.txt', 'w');
    $con = mysqli_connect("localhost","root","","login_db");
    mysqli_select_db($con, "login_db");
    /* insert field values into data.txt */
    $id = $_SESSION['user_id'];
    $query = "select lower_rate_limit, upper_rate_limit, ventrical_amplitude, 
    ventrical_pulse_width, ventrical_sensitivity, vrp, hysteresis, rate_smoothing, 
    atrial_amplitude, atrial_pulse_width, atrial_sensitivity, arp, pvarp, maximum_sensor_rate, 
    activity_threshold, reaction_time, response_factor, recovery_time from users where user_id = '$id' limit 1";
    //$query = "SELECT * FROM users";
    $result = mysqli_query($con,$query);   
    while ($row = mysqli_fetch_array($result)) {          
        $last = end($row);          
        $num = mysqli_num_fields($result) ;    
        for($i = 0; $i < $num; $i++) {            
            fwrite($fh, $row[$i]);                      
            if ($row[$i] != $last)
               fwrite($fh, ", ");
        }                                                                 
        fwrite($fh, "\n");
    }
    fclose($fh);
}

function empty_file(){
 
    $clear = fopen('data.txt', 'w');
    fclose($clear);

}

?>
