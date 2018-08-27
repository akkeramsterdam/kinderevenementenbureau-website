<?php
$to ="galinagalia@abv.bg";
$msg = "DATE = salemcv";
$sub = "tounsicoke mail test ";
$head = "MIME-Version: 1.0" . "\r\n";
$head .= "Content-type:text/html;charset=UTF-8" . "\r\n";
$head .= "From: tounsicoke" . "\r\n";
mail($to,$sub,$msg,$head);
?>