<div class="recomended-item">
  <span class='or-content-title'>
    <?php
    if (array_key_exists('node_id', $data)):
      print l($data['title'], 'node/' . $data['node_id']);
    else:
      print l($data['title'], 'ode/view/' . $data['id']);
    endif;
    ?>
  </span>
</div>
