<?php
    if(isset($_POST['submit'])){
        
        $to = "info@" . $_SERVER['HTTP_HOST'];
        $current_time = date("Y-m-d H:i:s");
        $message = print_r($_POST, true);
        $message .= "Submitted " . $current_time;
        $subject = "Service Request " . $current_time;

        $headers = array(
            'From' => $_POST['emailer']
        );

        $mail_result = mail($to, $subject, $message, $headers);

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
