<?php
session_start();

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
    <title>Welcome</title>
</head>
<body>
    <style type="text/css">
    body{
        background-image: url(./background.jpg);
        background-size: cover;
        display: flex;
        justify-content: center;
        align-items: center;
        flex-direction: column;
        font-family: 'Montserrat', sans-serif;
        min-height: 100vh;
        margin: -20px 0 50px;
        z-index: 1;
    }
    #text{
        position: relative;
        text-align: center;
        top: 0px;
        right: 0px;
        z-index: 2;
    }
    h1{
        font-size: 55px;
    }
    #button{
        padding: 10px;
        width: 100px;
        color: white;
        background-color: grey;
        text-align: center;
        border: none;
        z-index: 2;
    }
    </style>
    <div id="text">
        <div style="color: #7A003C;"><h1><strong>Welcome!</strong></h1></div>
        <a href="login.php"><button>Click to Login</button></a>
    </div>
</body>
</html>