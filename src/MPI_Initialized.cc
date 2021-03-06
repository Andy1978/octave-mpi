// Copyright (C) 2004-2007 Javier Fernández Baldomero, Mancia Anguita López
// Copyright (C) 2009 Riccardo Corradini <riccardocorradini@yahoo.it>
//
// This program is free software; you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free Software
// Foundation; either version 3 of the License, or (at your option) any later
// version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
// details.
//
// You should have received a copy of the GNU General Public License along with
// this program; if not, see <http://www.gnu.org/licenses/>.


/*
 * ----------------------------------------------------
 * Indicates whether MPI_Initialize has been called
 * [info flag] = MPI_Initialized
 * ----------------------------------------------------
 */

#include "mpi.h"
#include <octave/oct.h>

// PKG_ADD: autoload ("MPI_Initialized", "MPI_Init.oct");
DEFUN_DLD(MPI_Initialized, args, nargout,"-*- texinfo -*-\n\
@deftypefn {Loadable Function} {} [@var{FLAG} @var{INFO}] = MPI_Initialized\n\
Indicates whether MPI_Init has been executed.\n\
\n\
 @example\n\
 @group\n\
    @var{FLAG} (int) return code\n\
	    0 false\n\
            1 true\n\
    @var{INFO} (int) return code\n\
       0 MPI_SUCCESS    This function always returns MPI_SUCCESS\n\
SEE ALSO: MPI_Init, MPI_Finalize\n\
@end group\n\
@end example\n\
@end deftypefn")
{
  octave_value_list results;
   int flag;
   int info = MPI_Initialized (&flag);
    if (nargout > 1)
      results (1) = info;

    results(0) = octave_value (flag != 0);

   return results;
   /* [flag info] = MPI_Initialized */
}
