<?php
/**
 * @file
 * almost_engineer.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function almost_engineer_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Contact Header';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'contact_header';
  $fe_block_boxes->body = 'Feel free to ask us a question or just say hello!

Follow us on <a href="http://twitter.com/almostengr" target="_blank">Twitter @almostengr</a>. 
Check out our <a href="https://www.youtube.com/channel/UC4HCouBLtXD1j1U_17aBqig" target="_blank">YouTube channel</a>.';

  $export['contact_header'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Copyright';
  $fe_block_boxes->format = 'filtered_html';
  $fe_block_boxes->machine_name = 'copyright';
  $fe_block_boxes->body = 'Copyright &copy; 2015-2018 Almost Engineer';

  $export['copyright'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Create Account Description';
  $fe_block_boxes->format = 'plain_text';
  $fe_block_boxes->machine_name = 'create_account_detail';
  $fe_block_boxes->body = 'Need to create an account?  Purchase something from our Store.  Once you have completed your purchase, your account credentials will be emailed to the email address that you provide.';

  $export['create_account_detail'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Google AdSense';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'google_adsense';
  $fe_block_boxes->body = '<script async src="//pagead2.googlesyndication.com/pagead/js/adsbygoogle.js"></script>
<!-- website ad block -->
<ins class="adsbygoogle"
     style="display:block"
     data-ad-client="ca-pub-4218270188842097"
     data-ad-slot="3623527772"
     data-ad-format="auto"></ins>
<script>
(adsbygoogle = window.adsbygoogle || []).push({});
</script>';

  $export['google_adsense'] = $fe_block_boxes;

  return $export;
}
