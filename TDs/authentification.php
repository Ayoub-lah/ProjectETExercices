<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>authentification</title>
</head>
<body>
    
    <form action="authentification.php" method="POST">
        <label for="login"  name="login">Login : </label>
        <input type="text" di="login" name="login" placeholder="User Name">
        <br>
        <label for="pass" name="pass">Password :</label>
        <input type="password" id="pass" name="pass" placeholder="Password">
        <input type="submit" name="Identifier" >
    </form>

<?php

$MySql_Hot = 'localhost' ;
$MySql_User = 'root';
$MySql_pass = '';
$MySql_DB = 'authentification';

    $conn = mysqli_connect($MySql_Hot , $MySql_User , $MySql_pass , $MySql_DB) or die (mysqli_connect_error());
    
    $login = $_POST['login'];
    $pass = $_POST['pass'] ;

    $req = "select * from utilisateurs" ;
    $res = mysqli_query($conn , $req);
    
    $temp = 0;
    
    while($done = mysqli_fetch_array($res)){
        if($done[0]==$login && $done[1]==$pass)
            $temp=1;
    }
    
    if($temp==1)
        echo "Bein Venue au site " ;
    else
        echo "compte incorrect ";

    $sql = "SELECT pass FROM utilisateurs WHERE login = ?";
$stmt = $conn->prepare($sql);
$stmt->bind_param("s", $login);
$stmt->execute();
$result = $stmt->get_result();


$stmt->close();
$conn->close();





?>

</body>
</html>















<?php
// Traitement des données
$servername = "localhost";
$username = "root"; // Modifier si nécessaire
$password = ""; // Modifier si nécessaire
$dbname = "user_database";

// Connexion à la base de données
$conn = new mysqli($servername, $username, $password, $dbname);

// Vérifier la connexion
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$message = "";
$messageType = ""; // success ou error

if ($_SERVER["REQUEST_METHOD"] == "GET") {
    $action = $_GET['action'];
    $email = $_GET['email'];
    $password = $_GET['password'];

    if ($action === "signup") {
        $name = $_GET['name'];

        // Vérifier si l'utilisateur existe déjà
        $checkUser = $conn->prepare("SELECT * FROM users WHERE email = ?");
        $checkUser->bind_param("s", $email);
        $checkUser->execute();
        $result = $checkUser->get_result();

        if ($result->num_rows > 0) {
            $message = "User already exists. Please login.";
            $messageType = "error";
        } else {
            // Insérer l'utilisateur
            $hashedPassword = password_hash($password, PASSWORD_DEFAULT);
            $stmt = $conn->prepare("INSERT INTO users (name, email, password) VALUES (?, ?, ?)");
            $stmt->bind_param("sss", $name, $email, $hashedPassword);

            if ($stmt->execute()) {
                $message = "Account created successfully!";
                $messageType = "success";
            } else {
                $message = "Error: " . $stmt->error;
                $messageType = "error";
            }
        }
    } elseif ($action === "login") {
        // Vérifier les informations de connexion
        $stmt = $conn->prepare("SELECT * FROM users WHERE email = ?");
        $stmt->bind_param("s", $email);
        $stmt->execute();
        $result = $stmt->get_result();

        if ($result->num_rows === 1) {
            $user = $result->fetch_assoc();

            if (password_verify($password, $user['password'])) {
                $message = "Login successful. Welcome, " . htmlspecialchars($user['name']) . "!";
                $messageType = "success";
            } else {
                $message = "Invalid password.";
                $messageType = "error";
            }
        } else {
            $message = "No user found with this email.";
            $messageType = "error";
        }
    }
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login / Sign Up</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #f4f4f9;
            margin: 0;
            padding: 0;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
        }
        .alert {
            padding: 15px;
            margin-bottom: 20px;
            border: 1px solid transparent;
            border-radius: 4px;
            text-align: center;
            font-size: 16px;
        }
        .alert.success {
            color: #155724;
            background-color: #d4edda;
            border-color: #c3e6cb;
        }
        .alert.error {
            color: #721c24;
            background-color: #f8d7da;
            border-color: #f5c6cb;
        }
        .login-container {
            background: #fff;
            padding: 20px;
            border-radius: 5px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
            width: 300px;
        }
        .login-form h1 {
            text-align: center;
            margin-bottom: 20px;
        }
        .form-group {
            margin-bottom: 15px;
        }
        .form-group label {
            display: block;
            margin-bottom: 5px;
        }
        .form-group input {
            width: 100%;
            padding: 8px;
            border: 1px solid #ccc;
            border-radius: 5px;
        }
        .btn {
            width: 100%;
            padding: 10px;
            background: #007bff;
            border: none;
            color: white;
            border-radius: 5px;
            cursor: pointer;
        }
        .btn:hover {
            background: #0056b3;
        }
        .signup-link {
            text-align: center;
            margin-top: 10px;
        }
        .signup-link a {
            color: #007bff;
            text-decoration: none;
        }
        .signup-link a:hover {
            text-decoration: underline;
        }
        .message {
            margin: 10px 0;
            color: green;
            text-align: center;
        }
    </style>
</head>
<body>
    <div class="login-container">
    <?php if ($message): ?>
            <div class="alert <?php echo htmlspecialchars($messageType); ?>">
                <?php echo htmlspecialchars($message); ?>
            </div>
        <?php endif; ?>
        <form id="authForm" class="login-form" method="GET" action="">
            @csrf
            <h1 id="formTitle">Login</h1>
            <?php if ($message): ?>
                <p class="message"><?php echo htmlspecialchars($message); ?></p>
            <?php endif; ?>
            <div class="form-group" id="nameGroup" style="display: none;">
                <label for="name">Name</label>
                <input type="text" name="name" id="name" placeholder="Enter your name">
            </div>
            <div class="form-group">
                <label for="email">Email</label>
                <input type="email" name="email" id="email" placeholder="Enter your email" required>
            </div>
            <div class="form-group">
                <label for="password">Password</label>
                <input type="password" name="password" id="password" placeholder="Enter your password" required>
            </div>
            <input type="hidden" name="action" id="action" value="login">
            <button type="submit" class="btn" id="formButton">Login</button>
            <p class="signup-link" id="toggleLink">
                Don't have an account? <a href="#" onclick="toggleForm()">Sign up</a>
            </p>
        </form>
    </div>

    <script>
        function toggleForm() {
            const formTitle = document.getElementById('formTitle');
            const nameGroup = document.getElementById('nameGroup');
            const formButton = document.getElementById('formButton');
            const toggleLink = document.getElementById('toggleLink');
            const actionInput = document.getElementById('action');

            if (nameGroup.style.display === 'none') {
                formTitle.textContent = 'Sign up';
                nameGroup.style.display = 'block';
                formButton.textContent = 'Create Account';
                actionInput.value = 'signup';
                toggleLink.innerHTML = 'Already have an account? <a href="#" onclick="toggleForm()">Login</a>';
            } else {
                formTitle.textContent = 'Login';
                nameGroup.style.display = 'none';
                formButton.textContent = 'Login';
                actionInput.value = 'login';
                toggleLink.innerHTML = 'Don\'t have an account? <a href="#" onclick="toggleForm()">Sign up</a>';
            }
        }
    </script>
</body>
</html>
