$document().ready(function(){
function fetch_data{
  $.ajax({
      url:'select.php';
      method:'POST';
      success:function(data){
        $('#live_data').html(data);
      }
  });
}
});
