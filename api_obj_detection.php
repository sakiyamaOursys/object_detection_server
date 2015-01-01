<?php
    $fileName = 'test_img/' . $_FILES['file']['name']; 

  if (move_uploaded_file($_FILES['file']['tmp_name'], $fileName)) {
    chmod($fileName, 0644);
    $cascadeFileNameFullPath = "haarcascades/haarcascade_frontalface_default.xml";
    $exe = "./object_detection_main/build/obj_detection " . $fileName . " " . $cascadeFileNameFullPath;
//    echo $exe . "</br>\n";
    exec($exe, $output, $ret);
    if($ret === 0){//成功
    	header('Content-Type: application/json; charset=utf-8');
    	echo json_encode($output);
    }
  } else {
    echo "ファイルをアップロードできません。";
    var_dump($_FILES);
  }
?>