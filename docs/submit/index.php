<?php

$env_vars = "../../phpenv.php";
require_once($env_vars);

if(isset($_POST['emailer'])){
    $new_line = "\r\n";
    $current_time = date("Y-m-d H:i:s");
    $message = print_r($_POST, true);
    $message .= "Submitted " . $current_time . $new_line;
    $message .= "IP Address " . $_SERVER['REMOTE_ADDR'];
    $subject = $_POST['servicetype'] . " " . $current_time;
    $headers = array('From' => $_POST['emailer']);

    $mail_result = mail($HELPDESK_EMAIL, $subject, $message, $headers);

    if ($mail_result){
        header('Location: ' . $base_url . '/submission');
    }
    else {
        echo "Unexpected error occurred";
    }
}
else {
    header('Location: ' . $base_url);
}
?>
