#include <hdf5.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	__label__ fail_dset, fail_file;
	hid_t fid, dset;
	hid_t dtype_id;
	herr_t ret_val;
	char elts[1][255][255];

	if((fid = H5Fopen ("dataset/train_catvnoncat.h5", H5F_ACC_RDONLY, H5P_DEFAULT)) == H5I_INVALID_HID)
	{
		ret_val = EXIT_FAILURE;
		goto fail_file;
	}

	if((dset = H5Dopen(fid, "list_classes", H5P_DEFAULT)) == H5I_INVALID_HID) {
		ret_val = EXIT_FAILURE;
		goto fail_dset;
	}

//	if(H5Dread(dset, H5T_NATIVE_INT, H5S_ALL, H5S_ALL, H5P_DEFAULT, elts) < 0)
//		ret_val = EXIT_FAILURE;

	dtype_id = H5Dget_type(dset);
	printf("%s", H5Tget_class(dtype_id));

	H5Dclose(dtype_id);
	H5Dclose(dset);
	fail_dset:
		if(ret_val)
			printf("%d", ret_val);
		H5Fclose(fid);
	fail_file:
		if(ret_val)
			printf("%d", ret_val);

	return 0;
}
