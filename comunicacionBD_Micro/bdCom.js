$(document).ready(function(){
			$(".BD").click(function(){
				var status = $(this).attr('id');
				switch (status) {
					case 'Acknowledge':
						$.get("?http://172.16.101.131/1!");
						break;
				}
			});
		});
