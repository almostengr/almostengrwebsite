<?php

$env_vars = $_ENV['HOME'] . "/phpenv.php";
require_once($env_vars);

if(isset($_POST['submit'])){
    $new_line = "\r\n";
    $HELPDESK_EMAIL;
    $current_time = date("Y-m-d H:i:s");
    $message = print_r($_POST, true);
    $message .= "Submitted " . $current_time . $new_line;
    // $subject = "Service Request " . $current_time;
    $subject = $_POST['servicetype'] . $current_time;

    $headers = array(
        'From' => $_POST['emailer']
    );

    $mail_result = mail($HELPDESK_EMAIL, $subject, $message, $headers);

    if ($mail_result){
        header('Location: /submission');
    }
    else {
        echo "Unexpected error occurred";
    }
}
else {
    header('Location: /');
}
?>
