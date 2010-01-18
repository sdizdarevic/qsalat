package Salat.Android;

import java.text.SimpleDateFormat;
import java.util.Calendar;

import android.app.Activity;
import android.os.Bundle;
import android.os.Vibrator;
import android.widget.TextView;
import android.view.Menu;
import android.view.MenuInflater;

import android.app.AlarmManager;
import android.app.PendingIntent;
import android.util.Log;
import android.content.Context;
import android.content.Intent;
import android.widget.Toast;

public class SalatAndroid extends Activity {
	
	String times[] = new String[7];
	String[] dates = new String[4];	
	int year;
	int month;
	int day;
	private static final String TAG = "SomeApp "; 
	protected Toast mToast; 
	public String nextSalat;
	public Boolean isSalat;
	PendingIntent sender;
	Boolean firstTime = true;
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);    
 

        
        /*Intent i = getIntent();
        String action = i.getAction();
        Toast.makeText(SalatAndroid.this, " action  : "+action , Toast.LENGTH_LONG).show();
        if (action != null && action.equals("android.intent.category.START_THE_MUSIC"))
        {
             //setContentView(R.layout.pranked);
             //We'll need to start the music service here
        	
        	//finish();          	
        	
        	Toast.makeText(SalatAndroid.this, Integer.toString(day) , Toast.LENGTH_LONG).show();
        	//finish();     
        	//setContentView(R.layout.main);    
        	cal = Calendar.getInstance();
        	year = cal.get(java.util.Calendar.YEAR);
            month = cal.get(java.util.Calendar.MONTH);
            day = cal.get(java.util.Calendar.DAY_OF_MONTH) + 1;
        	init();
        	//day = 17;
        	//prayers = new Salat();
        	//init();
        	//TextView date1Text =	(TextView)  findViewById(R.id.date1Text);
        	//Toast.makeText(SalatAndroid.this, (CharSequence) date1Text , Toast.LENGTH_LONG).show();
    		//date1Text.setText("1 " +  " Muharrem " + "1432"); 
    		/*Hijri hijri = new Hijri();		
    		String[] dates = new String[4];
    		dates = hijri.isToString(year,month+1,day,0);
    		TextView date1Text =	(TextView)  findViewById(R.id.date1Text);
    		date1Text.setText(dates[0] + " " + dates[1] + " " + dates[3]);*/
        	//finish(); 
        	//startTimer(10000);*/
       /* }
        else
        {
        	setContentView(R.layout.main);
        	init();  
        	long ms = getNextSalat();
        	startTimer(10000);        	
        }*/        
        setContentView(R.layout.main);
        initCalendar();     
        setSalatTimes();
        setHijriDate();      
        printFajrTime();
        printDuhrTime();
        printAsrTime();
        printMaghribTime();
        printIshaTime();
        printShouroukTime();  
        
        long ms = getNextSalat();
    	startTimer(ms); 
    }
    
    public void onNewIntent(Intent intent) 
    {
    	String action = intent.getAction();
        Toast.makeText(SalatAndroid.this, " action  : "+action , Toast.LENGTH_LONG).show();
    	//TextView date1Text =	(TextView)  findViewById(R.id.date1Text);
    	//date1Text.setText("1 " +  " Muharrem " + "1432"); 
    	Calendar cal = Calendar.getInstance();
    	year = cal.get(java.util.Calendar.YEAR);
        month = cal.get(java.util.Calendar.MONTH);
        day = cal.get(java.util.Calendar.DAY_OF_MONTH);
        //Toast.makeText(SalatAndroid.this, "OK" , Toast.LENGTH_LONG).show();
        if (action.equals("android.intent.category.START_ATHAN"))
        {
	        if (isSalat) 
	        {
	        	Toast.makeText(SalatAndroid.this, "It's Salat " + nextSalat + "time ", Toast.LENGTH_LONG).show();
	        	//startTimer(getNextSalat());
	        	long ms = getNextSalat();
	        	startTimer(ms); 
	        	
	        }
	        else
	        {
	        	Toast.makeText(SalatAndroid.this, "It's not Salat time ", Toast.LENGTH_LONG).show();
	        	setHijriDate(); 
	            setSalatTimes();
	            printFajrTime();
	            printDuhrTime();
	            printAsrTime();
	            printMaghribTime();
	            printIshaTime();
	            printShouroukTime();
	            long ms = getNextSalat();
	        	startTimer(ms); 
	        }
        }        
    }
    
    public boolean onCreateOptionsMenu(Menu menu) {
        MenuInflater inflater = getMenuInflater();
        inflater.inflate(R.menu.options_menu, menu);
        return true;
    }
    
    /*public void init()
    {
    	initCalendar();     
        setSalatTimes();
        setHijriDate();      
        printFajrTime();
        printDuhrTime();
        printAsrTime();
        printMaghribTime();
        printIshaTime();
        printShouroukTime(); 
    }*/
    
    public void initCalendar()
    {    	
    	Calendar cal = Calendar.getInstance();
        year = cal.get(java.util.Calendar.YEAR);
        month = cal.get(java.util.Calendar.MONTH);
        day = cal.get(java.util.Calendar.DAY_OF_MONTH); 
    }
    
    public void setSalatTimes()
    {    	
    	Salat prayers = new Salat();
		prayers.setCalcMethod(2);
		prayers.setAsrMethod(0);
		prayers.setDhuhrMinutes(0);
		prayers.setHighLatsMethod(0);
		
		times = prayers.getDatePrayerTimes(year,month+1,day,45.5454,-73.6391,-5); 
    }
    
    public void setHijriDate()
    {
    	Hijri hijri = new Hijri();		
		dates = hijri.isToString(year,month+1,day,0);
		TextView date1Text =	(TextView)  findViewById(R.id.date1Text);
		date1Text.setText(dates[0] + " " + dates[1] + " " + dates[3]); 
    }
    
    public void printFajrTime()
    {    	
    	TextView fajrText =	(TextView)  findViewById(R.id.fajrText);
        fajrText.setText(times[0]); 
    }
    
    public void printDuhrTime()
    {
    	TextView duhrText =	(TextView)  findViewById(R.id.duhrText);
        duhrText.setText(times[2]); 
    }
    
    public void printAsrTime()
    {
    	TextView asrText =	(TextView)  findViewById(R.id.asrText);
        asrText.setText(times[3]); 
    }
    
    public void printMaghribTime()
    {
    	TextView maghribText =	(TextView)  findViewById(R.id.maghribText);
        maghribText.setText(times[5]); 
    }
    
    public void printIshaTime()
    {
    	TextView ishaText =	(TextView)  findViewById(R.id.ishaText);
        ishaText.setText(times[6]); 
    }
    
    public void printShouroukTime()
    {
    	TextView shouroukText =	(TextView)  findViewById(R.id.shouroukText);
        shouroukText.setText(times[1]); 
    }
    
    private long timeDiff(Calendar calendar1, Calendar calendar2)
    {
        long milliseconds1 = calendar1.getTimeInMillis();
        long milliseconds2 = calendar2.getTimeInMillis();
        long diff = milliseconds2 - milliseconds1;      
        
        return diff;
        
    }
    
    public long getNextSalat()
    {
    	long timeLeft = 0;
    	if (getFajr() > 0) 
    	{
     		nextSalat = "Fajr";
     		isSalat = true;
     		timeLeft = getFajr();
    	}
    	else if (getDuhr() > 0) 
    	{
    		nextSalat = "Duhr";
    		isSalat = true;
    		timeLeft = getDuhr();
    	}
    	else if (getAsr() > 0) 
    	{
    		nextSalat = "Asr";
    		isSalat = true;
    		timeLeft = getAsr();
    	}
    	else if (getMaghrib() > 0)
    	{
    		nextSalat = "Maghrib";
    		isSalat = true;
    		timeLeft = getMaghrib();
    	}
    	else if (getIsha() > 0)
    	{
    		nextSalat = "Isha";
    		isSalat = true;
    		timeLeft = getIsha();
    	}
    	else if (getMidNight() > 0)
    	{  
    		nextSalat = "Fajr";
    		isSalat = false;
    		timeLeft = getMidNight();
    	}    	
    	return timeLeft;
    }
    
    private long getFajr()
    {
    	Calendar cal = Calendar.getInstance();
    	String[] times_ = times[0].split(":");
    	Calendar time_ = Calendar.getInstance();
    	time_.set(year, month, day, Integer.parseInt(times_[0]), Integer.parseInt(times_[1]),0);
    	long diff = timeDiff(cal,time_);
    	long diff_ = getTimeInMS(6,02) - getCurrentTimeInMS();        
        Toast.makeText(SalatAndroid.this, Long.toString(diff_) + " / " + Long.toString(diff) , Toast.LENGTH_LONG).show();
    	return diff_;
    }
    
    private long getDuhr()
    {
    	Calendar cal = Calendar.getInstance();
    	String[] times_ = times[2].split(":");
    	Calendar time_ = Calendar.getInstance();
    	time_.set(year, month, day, Integer.parseInt(times_[0]), Integer.parseInt(times_[1]),0);
    	long diff = timeDiff(cal,time_);
    	long diff_ = getTimeInMS(12,05) - getCurrentTimeInMS();        
        Toast.makeText(SalatAndroid.this, Long.toString(diff_) + " / " + Long.toString(diff) , Toast.LENGTH_LONG).show();
    	return diff_;
    }
    
    private long getAsr()
    {
    	Calendar cal = Calendar.getInstance();
    	String[] times_ = times[3].split(":");
    	Calendar time_ = Calendar.getInstance();
    	time_.set(year, month, day, Integer.parseInt(times_[0]), Integer.parseInt(times_[1]),0);
    	long diff = timeDiff(cal,time_);
    	long diff_ = getTimeInMS(14,21) - getCurrentTimeInMS();        
        Toast.makeText(SalatAndroid.this, Long.toString(diff_) + " / " + Long.toString(diff) , Toast.LENGTH_LONG).show();
    	return diff_;
    }
    
    private long getMaghrib()
    {
    	Calendar cal = Calendar.getInstance();
    	String[] times_ = times[5].split(":");
    	Calendar time_ = Calendar.getInstance();
    	time_.set(year, month, day, Integer.parseInt(times_[0]), Integer.parseInt(times_[1]),0);
    	long diff = timeDiff(cal,time_);
    	long diff_ = getTimeInMS(16,41) - getCurrentTimeInMS();      
    	Toast.makeText(SalatAndroid.this, Long.toString(diff_) + " / " + Long.toString(diff) , Toast.LENGTH_LONG).show();        
    	return diff_;
    }
    
    private long getIsha()
    {
    	Calendar cal = Calendar.getInstance();
    	String[] times_ = times[6].split(":");
    	Calendar time_ = Calendar.getInstance();
    	time_.set(year, month, day, Integer.parseInt(times_[0]), Integer.parseInt(times_[1]),0);
    	long diff = timeDiff(cal,time_);
    	long diff_ = getTimeInMS(18,9) - getCurrentTimeInMS();        
        Toast.makeText(SalatAndroid.this, Long.toString(diff_) + " / " + Long.toString(diff) , Toast.LENGTH_LONG).show();        
    	return diff_;
    }
    
    private long getMidNight()
    {
    	Calendar cal = Calendar.getInstance();
    	Calendar time_ = Calendar.getInstance();
    	time_.set(year, month, day, 24, 00);
    	long diff = timeDiff(cal,time_);
    	long diff_ = getTimeInMS(24,0) - getCurrentTimeInMS();        
        Toast.makeText(SalatAndroid.this, Long.toString(diff_) + " / " + Long.toString(diff) , Toast.LENGTH_LONG).show();        
    	return diff_;
    }
    
    private void startTimer(long timeLeft)
    {    	         
    	Calendar cal = Calendar.getInstance();
    	long ms = cal.getTimeInMillis();
    	AlarmManager am = (AlarmManager) getSystemService(ALARM_SERVICE);    		
    	am.cancel(sender);
		Intent intent = new Intent(SalatAndroid.this, AReceiver.class);
    	sender = PendingIntent.getBroadcast(this, 999999999, intent, 0);    		
    	am.set(AlarmManager.RTC_WAKEUP, ms+timeLeft, sender); 
    	Toast.makeText(SalatAndroid.this, " Next Salat is "+nextSalat , Toast.LENGTH_LONG).show();    		
    }    
    
    private long getCurrentTimeInMS()
    {
        Calendar cal = Calendar.getInstance();
        SimpleDateFormat sdf1 = new SimpleDateFormat("ss");
        SimpleDateFormat sdf2 = new SimpleDateFormat("mm");
        SimpleDateFormat sdf3 = new SimpleDateFormat("HH");              
         
        long ms1 = Long.parseLong(sdf1.format(cal.getTime()))*1000;
        long ms2 = Long.parseLong(sdf2.format(cal.getTime()))*60*1000;
        long ms3 = Long.parseLong(sdf3.format(cal.getTime()))*3600*1000;


        return ms1+ms2+ms3;    
    }
   
    private long getTimeInMS(long hour, long min)
    {
        return hour*3600*1000+min*60*1000;
    }

    
}