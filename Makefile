nothing:

import-pC:
	cmsImportTask ./pC/ -u $(if $(s), , --no-statement)
