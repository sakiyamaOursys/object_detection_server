<?php
    $fileName = 'test_img/' . $_FILES['file']['name']; 

  if (move_uploaded_file($_FILES['file']['tmp_name'], $fileName)) {
    chmod($fileName, 0644);
    $cascadeFileNameFullPath = "haarcascades/haarcascade_cat.xml";
    $exe = "./build/obj_detection " . $fileName . " " . $cascadeFileNameFullPath;
//    echo $exe . "</br>\n";
    exec($exe, $output, $ret);
    var_dump($output);
    echo $ret;
  } else {
    echo "ファイルをアップロードできません。";
  }
?>