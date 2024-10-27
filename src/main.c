#include <hdf5.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
	__label__ fail_dset, fail_file;
	herr_t ret_val;
	hid_t fid, dset;
	hid_t memtype, space_id;
	int storage_size;

	if((fid = H5Fopen ("dataset/train_catvnoncat.h5", H5F_ACC_RDONLY, H5P_DEFAULT)) == H5I_INVALID_HID)
	{
		ret_val = EXIT_FAILURE;
		goto fail_file;
	}

	if((dset = H5Dopen(fid, "list_classes", H5P_DEFAULT)) == H5I_INVALID_HID) {
		ret_val = EXIT_FAILURE;
		goto fail_dset;
	}

	memtype = H5Tcopy(H5T_C_S1);
	H5Tset_size(memtype, 7);
	H5Tset_strpad(memtype, H5T_STR_NULLPAD);
	H5Tset_cset(memtype, H5T_CSET_ASCII);

	storage_size = H5Dget_storage_size(dset);
	space_id = H5Dget_space(dset);

	char *s = (char*)malloc(storage_size * sizeof(char));
	memset(s, 0, storage_size);

	if(H5Dread(dset, memtype, space_id, H5S_ALL, H5P_DEFAULT, s) < 0)
		ret_val = EXIT_FAILURE;

	printf("%s\n", s);
	//for (int i = 0; i < storage_size; i++)
	printf("%d", storage_size);

	free(s);
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
