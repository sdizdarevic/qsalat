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
	
	Calendar cal = Calendar.getInstance();
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
	long globalTime;
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);         
       
    	//Toast.makeText(SalatAndroid.this, "OnCreate", Toast.LENGTH_LONG).show();

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
    	Toast.makeText(SalatAndroid.this, "action : "+action, Toast.LENGTH_LONG).show();
    	//if (action.equals("android.intent.category.START_ATHAN"))
    	//{
	        /*Toast.makeText(SalatAndroid.this, " action  : "+action , Toast.LENGTH_LONG).show();
	    	Calendar cal = Calendar.getInstance();
	    	year = cal.get(java.util.Calendar.YEAR);
	        month = cal.get(java.util.Calendar.MONTH);
	        day = cal.get(java.util.Calendar.DAY_OF_MONTH);
	        if (isSalat) 
	        {
	        	Toast.makeText(SalatAndroid.this, "It's Salat : " + nextSalat, Toast.LENGTH_LONG).show();
	        }
	        else
	        {*/
	        	Toast.makeText(SalatAndroid.this, "It's not Salat time ", Toast.LENGTH_LONG).show();
	        	setHijriDate(); 
	            setSalatTimes();
	            printFajrTime();
	            printDuhrTime();
	            printAsrTime();
	            printMaghribTime();
	            printIshaTime();
	            printShouroukTime();
	       /* }
	        long ms = getNextSalat();
	    	//startTimer(ms); 
    	//}*/
        
    }
    
    public boolean onCreateOptionsMenu(Menu menu) {
        MenuInflater inflater = getMenuInflater();
        inflater.inflate(R.menu.options_menu, menu);
        return true;
    }    
    
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
    
    private long timeDiff(long hour, long min)
    {        
    	globalTime = getCurrentTimeInMS();
    	long diff = getTimeInMS(hour,min) - globalTime;
        return diff;       
    }
    
    public long getNextSalat()
    {
    	//Calendar cal = Calendar.getInstance();
    	long timeLeft = 0;
    	if (getFajr() > 0) 
    	{    		
     		nextSalat = "Fajr";
     		isSalat = true;
     		timeLeft = getFajr();
     		Toast.makeText(SalatAndroid.this, "Fajr "+Long.toString(timeLeft), Toast.LENGTH_LONG).show();
    	}
    	else if (getDuhr() > 0) 
    	{    		
    		nextSalat = "Duhr";
    		isSalat = true;
    		timeLeft = getDuhr();
    		Toast.makeText(SalatAndroid.this, "Duhr "+Long.toString(timeLeft), Toast.LENGTH_LONG).show();
    	}
    	else if (getAsr() > 0) 
    	{    		
    		nextSalat = "Asr";
    		isSalat = true;
    		timeLeft = getAsr();
    		Toast.makeText(SalatAndroid.this, "Asr "+Long.toString(timeLeft), Toast.LENGTH_LONG).show();
    	}
    	else if (getMaghrib() > 0)
    	{    		
    		nextSalat = "Maghrib";
    		isSalat = true;
    		timeLeft = getMaghrib();
    		Toast.makeText(SalatAndroid.this, "Maghrib "+Long.toString(timeLeft), Toast.LENGTH_LONG).show();
    	}
    	else if (getIsha() > 0)
    	{    		
    		nextSalat = "Isha";
    		isSalat = true;
    		timeLeft = getIsha();
    		Toast.makeText(SalatAndroid.this, "Isha "+Long.toString(timeLeft), Toast.LENGTH_LONG).show();
    	}
    	else if (getMidNight() > 0)
    	{      		
    		nextSalat = "Fajr";
    		isSalat = false;
    		timeLeft = getMidNight();
    		Toast.makeText(SalatAndroid.this, "Midnight "+Long.toString(timeLeft), Toast.LENGTH_LONG).show();
    	}    	
    	return timeLeft;
    }
    
    private long getFajr()
    {
    	//Calendar cal = Calendar.getInstance();
    	String[] times_ = times[0].split(":");
    	//Calendar time_ = Calendar.getInstance();
    	//time_.set(year, month, day, Integer.parseInt(times_[0]), Integer.parseInt(times_[1]));
		long diff = timeDiff(Long.parseLong(times_[0]),Long.parseLong(times_[1]));
		//Toast.makeText(SalatAndroid.this, "Fajr "+Long.toString(diff), Toast.LENGTH_LONG).show();
    	return diff;
    }
    
    private long getDuhr()
    {
    	//Calendar cal = Calendar.getInstance();
    	String[] times_ = times[2].split(":");
    	//Calendar time_ = Calendar.getInstance();
    	//time_.set(year, month, day, Integer.parseInt(times_[0]), Integer.parseInt(times_[1]));
    	long diff = timeDiff(Long.parseLong(times_[0]),Long.parseLong(times_[1]));
		//Toast.makeText(SalatAndroid.this, "Duhr "+Long.toString(diff), Toast.LENGTH_LONG).show();
    	return diff;
    }
    
    private long getAsr()
    {
    	//Calendar cal = Calendar.getInstance();
    	String[] times_ = times[3].split(":");
    	//Calendar time_ = Calendar.getInstance();
    	//time_.set(year, month, day, Integer.parseInt(times_[0]), Integer.parseInt(times_[1]));
    	long diff = timeDiff(Long.parseLong(times_[0]),Long.parseLong(times_[1]));
		//Toast.makeText(SalatAndroid.this, "Asr "+Long.toString(diff), Toast.LENGTH_LONG).show();
    	return diff;
    }
    
    private long getMaghrib()
    {
    	//Calendar cal = Calendar.getInstance();
    	String[] times_ = times[5].split(":");
    	//Calendar time_ = Calendar.getInstance();
    	//time_.set(year, month, day, Integer.parseInt(times_[0]), Integer.parseInt(times_[1]));
    	long diff = timeDiff(Long.parseLong(times_[0]),Long.parseLong(times_[1]));
		//Toast.makeText(SalatAndroid.this, "Maghrib "+Long.toString(diff), Toast.LENGTH_LONG).show();
    	return diff;
    }
    
    private long getIsha()
    {
    	//Calendar cal = Calendar.getInstance();
    	String[] times_ = times[6].split(":");
    	//Calendar time_ = Calendar.getInstance();
    	//time_.set(year, month, day, Integer.parseInt(times_[0]), Integer.parseInt(times_[1]));
    	long diff = timeDiff(Long.parseLong(times_[0]),Long.parseLong(times_[1]));
		//Toast.makeText(SalatAndroid.this, "Isha "+Long.toString(diff), Toast.LENGTH_LONG).show();
    	return diff;
    }
    
    private long getMidNight()
    {
    	//Calendar cal = Calendar.getInstance();
    	//Calendar time_ = Calendar.getInstance();
    	//time_.set(year, month, day, 24, 00);
    	long diff = timeDiff(24,0);
		//Toast.makeText(SalatAndroid.this, "Midnight "+Long.toString(diff), Toast.LENGTH_LONG).show();
    	return diff;
    }
    
    private void startTimer(long timeLeft)
    {    	         
    	//Calendar cal = Calendar.getInstance();
    	Toast.makeText(SalatAndroid.this, " time left "+Long.toString(timeLeft), Toast.LENGTH_LONG).show();
    	/*long ms = getCurrentTimeInMS();
    	AlarmManager am = (AlarmManager) getSystemService(ALARM_SERVICE);    		
    	am.cancel(sender);
		Intent intent = new Intent(SalatAndroid.this, AReceiver.class);
    	sender = PendingIntent.getBroadcast(this, 999999999, intent, 0);    		
    	am.set(AlarmManager.RTC_WAKEUP, ms+timeLeft, sender); 
    	Toast.makeText(SalatAndroid.this, " Next Salat is "+nextSalat + " in "+ Long.toString(ms+timeLeft), Toast.LENGTH_LONG).show();
    	//am.cancel(sender);	*/
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