<?php
session_start();

?>

<!DOCTYPE html>
<html>
<head>
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