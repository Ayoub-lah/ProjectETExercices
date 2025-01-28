<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Creation Data Base</title>
</head>
<body>

<?php


$MySql_Hot = 'localhost' ;
$MySql_User = 'root';
$MySql_pass = '';
$MySql_DB = 'gestion_de_clients';

$conn = mysqli_connect('localhost' , 'root' , '' , 'gestion_de_clients') or die (mysqli_connect_error());

$req = "select * from client " ;
$res = mysqli_query($conn , $req );

if(mysqli_num_rows($res)>0){
    echo "<table border='1'> " ;
    echo "<tr><th>Idclient</th><th>Nom</th><th>Adress</th><th>Ville</th><th>Telephone</th></tr>" ; 
    while($row = mysqli_fetch_assoc($res)){
        echo "<tr>" ; 
        echo "<td>" .$row['Idclient'] ."</td>" ;
        echo "<td>" .$row['Nom'] ."</td>" ;
        echo "<td>" .$row['Adress'] ."</td>" ;
        echo "<td>" .$row['Ville'] ."</td>" ;
        echo "<td>" .$row['Telephone'] ."</td>" ;
        echo "</tr>" ;
    }
    echo "</table>" ;
}else
    echo "pas de colon trouve " ;
    mysqli_free_result($res);

?>
</body>
</html>