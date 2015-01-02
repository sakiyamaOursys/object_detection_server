<?php
    
    $fileName = 'test_img/' . $_FILES['file']['name']; 

    //アップロードされた画像を保存
    if (move_uploaded_file($_FILES['file']['tmp_name'], $fileName)) {
        chmod($fileName, 0644);
	//読み込む学習データのファイルパス
        $cascadeFileNameFullPath = "haarcascades/haarcascade_frontalface_default.xml";
	//実行するコマンド
        $exe = "./object_detection_main/build/obj_detection " . $fileName . " " . $cascadeFileNameFullPath;
	//コマンドの実行	
        exec($exe, $output, $ret);
	if($ret === 0){//成功
	    //json形式でレスポンス
	    header('Content-Type: application/json; charset=utf-8');
	    echo json_encode($output);
	}
    } else {
      echo "ファイルをアップロードできません。";
    }
?>