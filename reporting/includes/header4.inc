<?php
/**********************************************************************
    Copyright (C) FrontAccounting, LLC.
	Released under the terms of the GNU General Public License, GPL, 
	as published by the Free Software Foundation, either version 3 
	of the License, or (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  
    See the License here <http://www.gnu.org/licenses/gpl-3.0.html>.
***********************************************************************/

/**
	Document blueprint use following parameters set in doctext.inc:

	$Addr1,	$Addr2 - address info
	$Payment_Terms - payment terms line
	$Footer - footer texts
	$this->company - company info
	$this->title - report title
	$this->formData - some other info
***/

		$this->row = $this->pageHeight - $this->topMargin;

		$upper = $this->row - 2 * $this->lineHeight;
		$lower = $this->bottomMargin + 8 * $this->lineHeight;
		$iline1 = $upper - 10.5 * $this->lineHeight;
		$iline2 = $iline1 - 1.5 * $this->lineHeight;
		$iline3 = $iline2 - 30.5 * $this->lineHeight;
		
		$iline4 = $lower+20;
		$right = $this->pageWidth - $this->rightMargin;
		$width = ($right - $this->leftMargin) / 5;
		$icol = $this->pageWidth / 2;
		$ccol = $this->cols[0] + 4;
		
		$c2col = $ccol + 60;
		$ccol2 = $icol / 2;
		$mcol = $icol + 8;
		$mcol2 = $this->pageWidth - $ccol2;
		$cols = count($this->cols);

		$this->fontSize += 4;
		$this->Font('bold');
		$this->TextWrap($ccol, $this->row, $this->pageWidth - $this->rightMargin - $ccol - 20, $this->company['coy_name'], 'center');
		$this->Font();
		$this->fontSize -= 4;
		$this->NewLine();
		$this->TextWrapLines($ccol, $this->pageWidth - $this->rightMargin - $ccol - 20, $this->company['postal_address'],'center');
		if (@$this->company['phone'])
		{
			$this->TextWrapLines($ccol, $this->pageWidth - $this->rightMargin - $ccol - 20, 'PH : '.$this->company['phone'],'center');
			
		}
		
		
		$this->NewLine();
		$this->TextWrap($ccol, $this->row, $this->pageWidth - $this->rightMargin - $ccol - 20, 'THE KERALA VALUE ADDED TAX RULES 2005 FORM NO 8B', 'center');
		$this->NewLine();
		$this->TextWrap($ccol, $this->row, $this->pageWidth - $this->rightMargin - $ccol - 20, 'CASH/CREDIT BILL', 'center');
		$this->NewLine();
		$this->TextWrap($ccol, $this->row, $this->pageWidth - $this->rightMargin - $ccol - 20, 'Duplicate Copy', 'center');

		$this->Text($ccol, 'TIN :', $icol);
		$this->NewLine();
		$this->Text($ccol, 'Bill No', $icol);
		$this->Text($c2col, ': '.$this->formData['document_number'], $icol);
		
		$this->NewLine();
		$this->Text($ccol, 'To', $icol);
		$rightT = $this->row;
		
		$this->Text($c2col, ': '.$Addr2['name'], $icol);
		$this->NewLine();
		$this->TextWrapLines($c2col, $icol - $ccol, $Addr2['address']);

		$this->Text($ccol, 'PH : '.$Addr2['contact'], $icol);
		$this->Text($ccol2+60, 'TIN No : ');

		$leftB = $this->row;

		//right top content
		$this->row = $rightT;
		$this->Text($mcol2, 'DATE : '.$this->formData['tran_date'], $icol);
		$this->NewLine();
		$this->Text($mcol2, 'PO NO : '.$Addr2['contact'], $icol);
		$this->NewLine();
		$this->Text($mcol2, 'PO DATE : '.$Addr2['contact'], $icol);
		$this->NewLine();
		$this->Text($mcol2, 'VECH NO : '.$Addr2['contact'], $icol);
		
		

		$this->Line($iline1);		  
		$this->Line($iline2);
		$this->Line($iline3);
		$this->Line($iline4);
	
		// Line headers
		$this->row = $iline1 - $this->lineHeight - 1;
		$this->Font('bold');
		$count = count($this->headers);
		$this->cols[$count] = $right - 3;
		for ($i = 0; $i < $count; $i++)
			$this->TextCol($i, $i + 1, $this->headers[$i], -2);
		$this->Font();

		// Footer
		$this->row = $iline4 - $this->lineHeight - 6;
		foreach ($Footer as $line => $txt)
		{
			if (!is_numeric($line))	// title => link
			{
				$this->Font('bold');
				$this->Text($ccol,  $line, 'L');
				$this->Font();
				$this->row -= $this->lineHeight;
				$this->fontSize -= 1;
				$this->TextWrapLines($ccol, $right - $ccol, ' '.$txt,'left');
				$this->fontSize += 1;
				
			}				
		}

		$this->TextCol(3,6, 'For '.$this->company['coy_name']);
		$this->NewLine(4);
		$this->TextCol(0,2, 'Prepared By');
		$this->TextCol(3,6, 'Authorised Signature');

		$this->Font();
		$temp = $iline2 - $this->lineHeight - 2;
?>
