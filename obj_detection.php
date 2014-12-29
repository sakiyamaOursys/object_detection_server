<?php
    $fileNameFullPath = $_GET["fileName"]; //"000_lena.jpg";
    $cascadeFileNameFullPath = "haarcascades/haarcascade_cat.xml";
    $exe = "./build/xml_detection " . $fileNameFullPath . " " . $cascadeFileNameFullPath;

    echo $exe . "</br>\n";
    system($exe, $ret);
    echo $ret;
?>