((nil . ((eval . (set (make-local-variable 'cmake-ide-build-dir)
		      (concat
		       (file-name-directory
		       (let ((d (dir-locals-find-file ".")))
			 (if (stringp d) d (car d))))
		       "build"))))))
