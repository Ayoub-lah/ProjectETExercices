<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="learn2.php" method="post">
    <input type="checkbox" name="pizza" value="piz">
    Pizza <br>
    <input type="checkbox" name="tacos" value="tac">
    Tacos <br>
    <input type="checkbox" name="hamburger" value="ham">
    Hamburger <br>
    <input type="checkbox" name="hotdog" value="hot"> 
    hotdog <br>
    <input type="submit" value="Submit" name="click">
    <br>
    </form>
</body>
</html>

<?php

    if(isset($_POST["click"])){
        
        if(isset($_POST["pizza"])){
            echo"you like pizza !!!!!!!!! <br>" ;
        }
        if(isset($_POST["tacos"])){
            echo "you like tacos";
        }



    }

?>