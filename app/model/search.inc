<?php
/*
class Search extends db {

	// wyświetla kategorie powiązane ze wpisem
	public function selectCategory($id_instruction) {

    	$sql = "select instructions_categories.id, instructions_categories.name 
		FROM instructions_categories 
		INNER JOIN instructions_categories_loop
		ON (instructions_categories.id = instructions_categories_loop.id_category) 
		WHERE instructions_categories_loop.id_instruction = $id_instruction";

	    $statement = $this->connect()->prepare($sql);
	    $statement->execute();

	    $result = $statement->fetchAll(PDO::FETCH_ASSOC);

	    return $result;
	}

	// wyświetla kategorie powiazane z wyszukiwaniem
	public function selectCategoryExpanded($search_keywords) {

    	$sql = "select * from instructions_categories where visibility=1 and name like '$search_keywords%'";

	    $statement = $this->connect()->prepare($sql);
	    $statement->execute();

	    $result = $statement->fetchAll(PDO::FETCH_ASSOC);

	    return $result;
	}

	//pagination & main select MySQL CODE


	// general select pagination
  	public function selectGeneral($search_keywords) {

    	//$sql = "select * from instructions where visibility=1";

  		$sql = "
			SELECT instructions.*  
		
			FROM instructions
			
			LEFT JOIN instructions_categories_loop
			
			ON instructions.id = instructions_categories_loop.id_instruction 
			
			WHERE
		"; 
		$search_keywords = mb_strtolower($search_keywords);
		$sk = explode('+',$search_keywords);
		for($i=0; $i<count($sk); $i++)
		{
			$sql .= " (instructions.visibility=1 AND (instructions.title LIKE '%$sk[$i]%' OR instructions.text LIKE '%$sk[$i]%')) ";
			
			$sql .= " OR (instructions.visibility=1 AND instructions.tags LIKE '%$sk[$i]%') ";

			if ($i < count($sk)-1) { $sql .= " OR "; }
		}

	    $statement = $this->connect()->prepare($sql);
	    $statement->execute();

	    $result = $statement->fetchAll(PDO::FETCH_ASSOC);

	    return $result;
	}
	// expanded select pagination // WYŚWIETLA WPISY
  	public function selectExpanded($number_pagination, $endPagination, $search_keywords) {			

		$startPagination = ($number_pagination-1) * $endPagination;

		$sql = "
			SELECT instructions.*  
		
			FROM instructions
			
			LEFT JOIN instructions_categories_loop
			
			ON instructions.id = instructions_categories_loop.id_instruction 
			
			WHERE
		"; 
		$search_keywords = mb_strtolower($search_keywords);
		$sk = explode('+',$search_keywords);
		for($i=0; $i<count($sk); $i++)
		{
			$sql .= " (instructions.visibility=1 AND (instructions.title LIKE '%$sk[$i]%' OR instructions.text LIKE '%$sk[$i]%')) ";
			
			$sql .= " OR (instructions.visibility=1 AND instructions.tags LIKE '%$sk[$i]%') ";

			//if ( !empty($id_category) ) { $sql .= " OR (instructions.visibility=1 AND instructions_categories_loop.id_category=$id_category) "; }
			if ($i < count($sk)-1) { $sql .= " OR "; }
		}
		$search_keywords = str_replace('+', ' ', $search_keywords);
		$sql .= "
			ORDER BY CASE
			
			WHEN instructions.title LIKE '%$search_keywords%' AND instructions.text LIKE '%$search_keywords%' THEN 1
			WHEN instructions.title LIKE '%$search_keywords%' THEN 2
			WHEN instructions.text LIKE '%$search_keywords%' THEN 3
			
			END DESC LIMIT $startPagination, $endPagination
		";

		$statement = $this->connect()->prepare($sql);
	    $statement->execute();

	    $result = $statement->fetchAll(PDO::FETCH_ASSOC);

	    return $result; 
	}


	//pagination HTML

	// Used by paginationHTML below...
	private function paginationLink($p, $page, $URL) {
		if ($p==$page) return '<b style="color:gold">' . $p . '</b>';
		return '<a href="' . $URL . $p . '">' . $p . '</a>';
	}
	// Used by paginationHTML below...
	private function paginationGap($p1, $p2) {
		$x = $p2-$p1;
		if ($x==0) return '';
		if ($x==1) return ' ';
		if ($x<=10) return ' [..] ';
		if ($x<=100) return ' .. ';
		return ' ... ';
	}
	// URL requires the $page number be appended to it.
	// e.g. it should end in '&page=' or something similar.
	public function paginationHTML($page, $lastPage, $URL) {
		$LINKS_PER_STEP = 5;
		$result = '
			<div id="pagination" class="pt-4 text-left text-xl-center">
		   		<nav aria-label="Pagination">
		      		<ul class="pagination">
		';
		// prev pages
		if ($page>1)
		  $result .= '
		    <li class="page-item">
		      <a class="page-link" href="' . $URL . '1" aria-label="Frist">
		        <i class="fas fa-angle-double-left"></i>
		      </a>
		    </li>
		    <li class="page-item">
		      <a class="page-link" href="' . $URL . ($page-1) . '" aria-label="Prev">
		        <i class="fas fa-angle-left"></i>
		      </a>
		    </li>
		  ';
		else 
		  $result .= '
		    <li class="page-item disabled">
		      <a class="page-link" href="#" aria-label="Frist">
		         <i class="fas fa-angle-double-left"></i>
		      </a>
		    </li>
		    <li class="page-item disabled">
		      <a class="page-link" href="#" aria-label="Prev">
		        <i class="fas fa-angle-left"></i>
		      </a>
		    </li>
		  ';
		// actual page
		$result .= '
		   <li class="page-item disabled">
		      <a class="page-link" href="#" aria-label="Active">
		       <span>' . $page . '</span>
		      </a>
		   </li>
		';
		// next pages
		if ($page<$lastPage)
		  $result .= '
		    <li class="page-item">
		      <a class="page-link" href="' . $URL . ($page+1) . '" aria-label="Next">
		        <i class="fas fa-angle-right"></i>
		      </a>
		    </li>
		    <li class="page-item">
		      <a class="page-link" href="' . $URL . $lastPage . '" aria-label="End">
		        <i class="fas fa-angle-double-right"></i>
		      </a>
		    </li>
		  ';
		else 
		  $result .= '
		    <li class="page-item disabled">
		      <a class="page-link" href="#" aria-label="Next">
		        <i class="fas fa-angle-right"></i>
		      </a>
		    </li>
		    <li class="page-item disabled">
		      <a class="page-link" href="#" aria-label="End">
		        <i class="fas fa-angle-double-right"></i>
		      </a>
		    </li>
		  ';
		$result .= '
		      		</ul>
		   		</nav>
		  		<span>
		';
		// main page links
		$lastp1 = 1;
		$lastp2 = $page;
		$p1 = 1;
		$p2 = $page;
		$c1 = $LINKS_PER_STEP+1;
		$c2 = $LINKS_PER_STEP+1;
		$s1 = '';
		$s2 = '';
		$step = 1;
		while (true)
		{
		  if ($c1>=$c2)
		  {
		    $s1 .= $this->paginationGap($lastp1,$p1) . $this->paginationLink($p1,$page,$URL);
		    $lastp1 = $p1;
		    $p1 += $step;
		    $c1--;
		  }
		  else
		  {
		    $s2 = $this->paginationLink($p2,$page,$URL) . $this->paginationGap($p2,$lastp2) . $s2;
		    $lastp2 = $p2;
		    $p2 -= $step;
		    $c2--;
		  }
		  if ($c2==0)
		  {
		    $step *= 10;
		    $p1 += $step-1;         // Round UP to nearest multiple of $step
		    $p1 -= ($p1 % $step);
		    $p2 -= ($p2 % $step);   // Round DOWN to nearest multiple of $step
		    $c1 = $LINKS_PER_STEP;
		    $c2 = $LINKS_PER_STEP;
		  }
		  if ($p1>$p2)
		  {
		    $result .= $s1 . $this->paginationGap($lastp1,$lastp2) . $s2;
			if (($lastp2>$page)||($page>=$lastPage)){
				$result .= '</span></div>';
				return $result;
			}
		    $lastp1 = $page;
		    $lastp2 = $lastPage;
		    $p1 = $page+1;
		    $p2 = $lastPage;
		    $c1 = $LINKS_PER_STEP;
		    $c2 = $LINKS_PER_STEP+1;
		    $s1 = '';
		    $s2 = '';
		    $step = 1;
		  }
		}
	}

	//rating HTML

	// draw rating stars
	public function ratingHTML($rating1, $rating2, $rating3, $rating4, $rating5) {
		
		$ratingValue = 0;
	    $coutNumbers = 0;
	    if ($rating1 == 0) {} else {
	      for ($r1=0; $r1 < $rating1; $r1++) { 
	        $ratingValue += 1;
	        $coutNumbers++;
	      }
	    }
	    if ($rating2 == 0) {} else {
	      for ($r2=0; $r2 < $rating2; $r2++) { 
	        $ratingValue += 2;
	        $coutNumbers++;
	      }
	    }
	    if ($rating3 == 0) {} else {
	      for ($r3=0; $r3 < $rating3; $r3++) { 
	        $ratingValue += 3;
	        $coutNumbers++;
	      }
	    }
	    if ($rating4 == 0) {} else {
	      for ($r4=0; $r4 < $rating4; $r4++) { 
	        $ratingValue += 4;
	        $coutNumbers++;
	      }
	    }
	    if ($rating5 == 0) {} else {
	      for ($r5=0; $r5 < $rating5; $r5++) { 
	        $ratingValue += 5;
	        $coutNumbers++;
	      }
	    }
	    $result = '<span id="rate" class="small">';
	    if ($ratingValue == 0) {
	      for ($ratingStars=0; $ratingStars < 5; $ratingStars++) { 
	        $result .= '<i class="fas fa-star py-2 px-1 rate-popover rate-normal" data-index="0" data-html="true" data-toggle="popover" data-placement="top" title="No rating"></i>';
	      }
	    } else {
	      $ratingValue = round($ratingValue/$coutNumbers, 2); 
	      $result .= '<span>' . $ratingValue . '</span>';
	      $ratingValue = (int) $ratingValue-1;
	      $starRating = array ('Very bad', 'Poor', 'OK', 'Good', 'Excellent');
	      for ($ratingStars=0; $ratingStars < 5; $ratingStars++) { 
	        if ($ratingStars <= $ratingValue) {
	          $result .= '<i class="fas fa-star py-2 px-1 rate-popover rate-gold" data-index="0" data-html="true" data-toggle="popover" data-placement="top" title="'.$starRating[$ratingValue].'"></i>';
	        }else{
	          $result .= '<i class="fas fa-star py-2 px-1 rate-popover rate-normal" data-index="0" data-html="true" data-toggle="popover" data-placement="top" title="'.$starRating[$ratingValue].'"></i>';
	        }
	      }
	    }
	    $result .= '</span>';

	    return $result;
	}


	//tag clouds HTML

	// wyświetla kategorie powiazane z wyszukiwaniem
	public function tagClouds($instructionID, $search_keywords) {
		
		$result = '';
    	$categoriesName = [];
        //$search_keywords_array = explode("+", $search_keywords);
        /*for ($i=0; $i < count($search_keywords_array); $i++) {   
         
          if (in_array($search_keywords_array[$i], $categories)) {

          } else {

            array_push($categories, $search_keywords_array[$i]);

            $selectCategoryExpanded = $this->selectCategoryExpanded($search_keywords_array[$i]);
            
            foreach ($selectCategoryExpanded as $data) {
              $result .= '
                <li id="tag_'.$data['id'].'">
                  <a href="'. URL .'search?cat='.$data['name'].'" title="'.$data['name'].'">'.ucwords($data['name']).'</a>
                </li>
              ';
            }  
          }
        }*

        $sql = "
			SELECT instructions_categories.*  

			FROM instructions_categories

			LEFT JOIN instructions_categories_loop

			ON instructions_categories.id = instructions_categories_loop.id_category 

			WHERE
		"; 
		for($i=0; $i<count($instructionID); $i++)
		{
			$sql .= "(
				instructions_categories.visibility=1 AND (
					instructions_categories_loop.id_instruction=$instructionID[$i] 
			";

			$search_keywords_array = explode("+", $search_keywords);
	        for ($j=0; $j < count($search_keywords_array); $j++) {    
	          	if (in_array($search_keywords_array[$j], $categoriesName)) {} else {
	            	array_push($categoriesName, $search_keywords_array[$j]);
	            	$sql .= " OR instructions_categories.name like '$search_keywords_array[$j]%'";
	         	}
	        }

			$sql .= "
				)
			)";

			if ($i < count($instructionID)-1) { $sql .= " OR "; }
		}
		$statement = $this->connect()->prepare($sql);
	    $statement->execute();
	    $result = $statement->fetchAll(PDO::FETCH_ASSOC);

	    //$result = $search_keywords;
	    return $result;
	
	}

}
*/