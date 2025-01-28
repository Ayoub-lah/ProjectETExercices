<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Calcule </title>
</head>
<body>
    
<for method="POST">
    <label for="option1">
        Option 1 :
    </label>
    <input type="number" name="option1" placeholder="Entre premiere nombre ">
    <label for="operation">Opération :</label>
    <select name="option" id="option">
        <option value="+">+</option>
        <option value="-">-</option>
        <option value="/">/</option>
        <option value="*">*</option>
    </select>
    <label for="option2">
        Option 2 :
    </label>
    <input type="number" name="option2" placeholder="Entre deuxieme nombre ">
    <input type="submit" name="result">
</for>

<?php 

    if($_SERVER["REQUEST_METHOD"]==="POST"){
        $option1=$_POST["option1"];
        $option = $_POST["option"];
        $option2 = $_POST["option2"];
        $result = null ;

        switch($option){
                case "+":
                    $result = $option1 + $option2;
                    break;
                case "-":
                    $result = $option1 - $option2;
                    break;
                case "*":
                    $result = $option1 * $option2;
                    break;
                case "/":
                    if ($option2 != 0) {
                        $result = $option1 / $option2;
                    } else {
                        $result = "Erreur : Division par zéro";
                    }
                    break;
                default:
                    $result = "Opération non valide";
            }
            echo $result ; 
        }











?>






















</body>
</html>