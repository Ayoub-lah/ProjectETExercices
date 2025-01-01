<?php
if (isset($_POST['delete'])) {
    require_once 'include/DB.php'; 
    
    $id = $_POST['id'];

    $sql = $conn->prepare("DELETE FROM items WHERE id = ?"); 
    $res = $sql->execute([$id]);

    header("Location: index.php"); 
    exit(); 
}
?>
