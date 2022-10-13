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
    <title>Pacemaker</title>
</head>
<body>
    <a href="logout.php">Logout</a>
    <h1>Welcome!</h1>

    <br>
    Hello, <?php echo $user_data['user_name']; ?>
</body>
</html>