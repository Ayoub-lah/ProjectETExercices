<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <br>

    <form action="" method="POST">
        <label for="Nom">Nom : </label>
        <input type="text" name="Nom" placeholder="Name">
        <br>
        <br>
        <label for="Prenom">Prenom : </label>
        <input type="text" name="Prenom" placeholder="Prenom">
        <br>
        <br>
        <label for="salaire">salaire : </label>
        <input type="number" name="salaire" placeholder="salaire">
        <br>
        <br>
        <label for="civil"> Etat civil :</label>
        <input type="radio" name="op"> 
        <label for="celebataire" >celebataire</label>
        <input type="radio" name="op"> 
        <label for="marie">marie</label>
        <br><br>
        <input type="submit">
        <input type="reset" name="Annuler">
    </form>

    <?php

    if($_SERVER["REQUEST_METHOD"]==="POST"){

        $salaire = $_POST["salaire"] ;

        if($salaire < 3000){
            $salaire -= $salaire * 0.05 ;
        }
        if($salaire >3000 && $salaire <6000){
            $salaire-=$salaire * 0.1 ; 
        }        
        if($salaire < 6000 && $salaire > 10000){
            $salaire -=$salaire * 0.15 ;
        }
        if($salaire >10000){
            $salaire -= $salaire * 0.4 ;
        }
            echo "<br>" ;
            echo "votre salire apres reduction est : ".$salaire  ;

    }

    ?>

</body>
</html>