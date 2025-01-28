<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="learn1.php" method="post">
        <input type="radio" value="visa" name="inp">
        Visa <br>
        <input type="radio" value="mastercard" name="inp">
        Mastercard <br>
        <input type="radio" value="american express" name="inp">
        american Express <br>
        <input type="submit" value="Submit" name="click">
    </form>
</body>
</html>

<?php

    if(isset($_POST["click"])){
        if(isset($_POST["inp"])){
            $creditCarte = $_POST["inp"] ;
            echo $creditCarte ; 
        }else{
            echo "please selection one " ;
        }
    }











?>