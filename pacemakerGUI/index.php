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
    <style type="text/css">
    body {
        background: linear-gradient(to right, white, #7A003C, #56002a);
    }
    </style>
    <h1>Welcome!</h1>
    Hello, <?php echo $user_data['user_name']; ?>
    <br>
    Serial Number: <?php echo $user_data['Serial_number']; ?>
    <br>
    <h2>Serial Number</h2>
    <form method="post">
        <input id="text" type="text" placeholder="Serial Number" name="serial_number" required>
        <input type="submit">
    </form>
    <?php
    if($_SERVER['REQUEST_METHOD'] == "POST"){
        //something was posted stored into variables
        $serial_number = $_POST["serial_number"];
        if($serial_number==$user_data['Serial_number']){
            echo "<br>";
            echo "Pacemaker connected successfully!";
        }
        else{
            echo "<br>";
            echo "Pacemaker is not attached to this user!";
        }
        
    }
    ?>
    <h2>Pacemaker Modes</h2>
    <a href="AOO.php"><button>AOO</button></a>
    <br>
    <br>
    <a href="VOO.php"><button>VOO</button></a>
    <br>
    <br>
    <a href="AAI.php"><button>AAI</button></a>
    <br>
    <br>
    <a href="VVI.php"><button>VVI</button></a>
    <br>
    <h2>Date and Time</h2>
    <a href="DateTime.php"><button>Edit</button></a>
    <br>
    <br>
    <a href="logout.php">Logout</a>
</body>
</html>