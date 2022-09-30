function externalLinks() {
    var anchors = document.getElementsByTagName('a');
    for (var i = 0; i < anchors.length; i++) {
        if (anchors[i].getAttribute("href").startsWith("http")) {
            anchors[i].target = "_blank";
        }
    }
}

function facebookChat() {
    window.fbAsyncInit = function () {
        FB.init({
            xfbml: true,
            version: 'v10.0'
        });
    };
    (function (d, s, id) {
        var js, fjs = d.getElementsByTagName(s)[0];
        if (d.getElementById(id)) return;
        js = d.createElement(s); js.id = id;
        js.src = 'https://connect.facebook.net/en_US/sdk/xfbml.customerchat.js';
        fjs.parentNode.insertBefore(js, fjs);
    }(document, 'script', 'facebook-jssdk'));
}

function checkNewsletterform() {
    re = /^\w+([.-]?\w+)@\w+([.-]?\w+)(.\w{2,3})+$/;
    if (!(re.test(jQuery("#email").val()))) {
        jQuery("#result").empty().append("Please enter a valid email address");
        jQuery("#email").focus();
        return false;
    }
    return true;
}

function submitNewsletterForm() {
    successMessage = 'Thank you for your registration. Please check your email to confirm.';
    data = jQuery('#subscribeform').serialize();
    jQuery.ajax({
        type: 'POST',
        data: data,
        // url: 'https://installationname.yourdomain.com/lists/?p=subscribe&id=1',
        url: 'https://rhtservices.net/rhtnewsletter/?p=subscribe&id=1',
        dataType: 'html',
        success: function(data, status, request) {
            jQuery("#result").empty().append(data != '' ? data : successMessage);
            jQuery('#email').val('');
        },
        error: function(request, status, error) {
            alert('Sorry, we were unable to process your subscription.');
        }
    });
}

externalLinks();
// fadeIn();
facebookChat();