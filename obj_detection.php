<?php
    $fileNameFullPath = "test_img/" . $_GET["fileName"]; //"000_lena.jpg";
    $cascadeFileNameFullPath = "haarcascades/haarcascade_cat.xml";
    $exe = "./build/obj_detection " . $fileNameFullPath . " " . $cascadeFileNameFullPath;

    echo $exe . "</br>\n";
    system($exe, $ret);
    echo $ret;
?>