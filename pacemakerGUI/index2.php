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
    <title>Pacemaker</title>
</head>
<body>
    <!-- css styling -->
    <style type="text/css">
    body {
        background: linear-gradient(to right, white, #7A003C, #56002a);
    }
    </style>
    <br>
    <strong>Connection:</strong> <?php echo "Pacemaker with serial number ".$user_data['Serial_number']." successfully connected!"; ?>
    <!-- mode buttons -->
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