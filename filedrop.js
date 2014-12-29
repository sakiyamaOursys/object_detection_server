(function(global, $) {
    "use strict";
 
    var util = {
        stop: function(e) {
            e.preventDefault();
            e.stopPropagation();
        },
        // str???????????
        cutoff: function(str, len, tail) {
            tail = tail || "";
            return str.slice(0, len) + tail;
        }
    }
 
 
    $(function() {
        var $dropArea = $("#dropable");
 
        $dropArea.on({
            "dragenter": util.stop,
            "dragover": util.stop,
            "dragleave": util.stop,
            "drop": function(e) {
                util.stop(e);
 
                var tmp = e.originalEvent.dataTransfer.files,
                    files = Array.prototype.slice.call(tmp, 0, tmp.length);
 
                files.forEach(function(file) {
 
                    var reader = new FileReader();
 
                    $(reader).one('load', function(e) {
                        var fn = "ドロップされたファイル名" + file.name,
                            ft = "ファイル形式" + file.type,
                            fs = "ファイルサイズ" + file.size + " Byte",
                            fv = "内容" + util.cutoff(e.target.result, 80, "...[?]"),
                            msg = [fn, ft, fs, fv].join("\n");
 
                        $dropArea.append( $("<pre></pre>").text(msg) );
                    }); 
                    reader.readAsText(file);
                });
            }
        });
    });
}(this, jQuery));