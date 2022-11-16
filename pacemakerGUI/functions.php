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
?>
