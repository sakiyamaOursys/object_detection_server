//外部jsの読み込み
document.write('<script type="text/javascript" charset="UTF-8" src="vender/OpenCVjs/javascript/module/core.js"></script>');
document.write('<script type="text/javascript" charset="UTF-8" src="vender/OpenCVjs/javascript/module/imgcodecs.js"></script>');
document.write('<script type="text/javascript" charset="UTF-8" src="vender/OpenCVjs/javascript/module/imgproc.js"></script>');
document.write('<script type="text/javascript" charset="UTF-8" src="vender/OpenCVjs/javascript/module/ml.js"></script>');
document.write('<script type="text/javascript" charset="UTF-8" src="vender/OpenCVjs/javascript/module/highgui.js"></script>');

//開発中メソッド
document.write('<script type="text/javascript" charset="UTF-8" src="vender/OpenCVjs/javascript/module/00_develop.js"></script>');

//test用メソッド
document.write('<script type="text/javascript" charset="UTF-8" src="vender/OpenCVjs/javascript/module/test.js"></script>');

//test実行用のメソッド
// document.write('<script type="text/javascript" charset="UTF-8" src="vender/OpenCVjs/javascript/module/run_test.js"></script>');

//メモ
//imgタグの画像から直接IplImage型へは変換できない
//ローカルの画像ファイルはクロスドメイン扱いとなりjavascriptのエラーが出る